#!/usr/bin/env bash

outFolder="${1:-out}"
mkdir -p $outFolder

directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
mkdir -p graphs

attacks=(DropFindNodeAttack IsSiblingAttack InvalidNodesAttack DropRouteMessageAttack InvalidDataAttack ResolveToSelfAttack IsSiblingAndResolveToSelfAttack)
ratios=(0.0 0.1 0.2 0.3 0.4 0.5)
runs=20

for attack in ${attacks[@]}; do
    for malicious_ratio in ${ratios[@]}; do
        for with_challenge in true false; do
            for run in `seq $runs`; do
                $directory/run_retry.sh $outFolder $attack $malicious_ratio $with_challenge $run &
            done
            wait
        done
    done
done
