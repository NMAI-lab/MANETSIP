#!/usr/bin/env bash

inFolder="${1:-in}"
outFolder="${2:-out}"

mkdir -p $outFolder

z=1.96 # 95% confidence interval

attacks=(DropFindNodeAttack IsSiblingAttack InvalidNodesAttack DropRouteMessageAttack InvalidDataAttack ResolveToSelfAttack IsSiblingAndResolveToSelfAttack)
ratios=(0.0 0.1 0.2 0.3 0.4 0.5)
runs=20

for attack in ${attacks[@]}; do
    for with_challenge in true false; do
        echo malicious_ratio,peers,fails,semiSuccess,success,peersError,failsError,semiSuccessError,successError > $outFolder/${attack}_${with_challenge}.csv

        for malicious_ratio in ${ratios[@]}; do
            num=0
            peers=0
            fails=0
            semiSuccess=0
            success=0

            for run in `seq $runs`; do
                file=$inFolder/${attack}_${malicious_ratio}_${with_challenge}_${run}.log
                [ -e $file ] || continue

                readarray -t stats < $file
                totalResolves=`echo "${stats[1]} + ${stats[2]} + ${stats[3]}" | bc`

                let peers+=${stats[0]}
                fails=`echo "scale=10; $fails + (${stats[1]} / $totalResolves)" | bc`
                semiSuccess=`echo "scale=10; $semiSuccess + (${stats[2]} / $totalResolves)" | bc`
                success=`echo "scale=10; $success + (${stats[3]} / $totalResolves)" | bc`

                let num+=1
            done

            (( num == 0 )) && continue
            averagePeers=`echo "scale=10; $peers / $num" | bc`
            averageFails=`echo "scale=10; $fails / $num" | bc`
            averageSemiSuccess=`echo "scale=10; $semiSuccess / $num" | bc`
            averageSuccess=`echo "scale=10; $success / $num" | bc`

            peersDiffSum=0
            failsDiffSum=0
            semiSuccessDiffSum=0
            successDiffSum=0
            for run in `seq $runs`; do
                file=$inFolder/${attack}_${malicious_ratio}_${with_challenge}_${run}.log
                [ -e $file ] || continue

                readarray -t stats < $file
                totalResolves=`echo "${stats[1]} + ${stats[2]} + ${stats[3]}" | bc`

                peersDiffSum=`echo "scale=10; $peersDiffSum + (${stats[0]} - $averagePeers)^2" | bc`
                failsDiffSum=`echo "scale=10; $failsDiffSum + ((${stats[1]} / $totalResolves) - $averageFails)^2" | bc`
                semiSuccessDiffSum=`echo "scale=10; $semiSuccessDiffSum + ((${stats[2]} / $totalResolves) - $averageSemiSuccess)^2" | bc`
                successDiffSum=`echo "scale=10; $successDiffSum + ((${stats[3]} / $totalResolves) - $averageSuccess)^2" | bc`
            done

            peersStdDev=`echo "scale=10; sqrt($peersDiffSum/$num)" | bc`
            failsStdDev=`echo "scale=10; sqrt($failsDiffSum/$num)" | bc`
            semiSuccessStdDev=`echo "scale=10; sqrt($semiSuccessDiffSum/$num)" | bc`
            successStdDev=`echo "scale=10; sqrt($successDiffSum/$num)" | bc`

            peersError=`echo "scale=10; $z * $peersStdDev / sqrt($num)" | bc`
            failsError=`echo "scale=10; $z * $failsStdDev / sqrt($num)" | bc`
            semiSuccessError=`echo "scale=10; $z * $semiSuccessStdDev / sqrt($num)" | bc`
            successError=`echo "scale=10; $z * $successStdDev / sqrt($num)" | bc`

            echo $malicious_ratio,$averagePeers,$averageFails,$averageSemiSuccess,$averageSuccess,$peersError,$failsError,$semiSuccessError,$successError >> $outFolder/${attack}_${with_challenge}.csv
        done
    done
done
