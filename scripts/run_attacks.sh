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
# directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
# mkdir -p graphs

# attacks=(DropFindNodeAttack SiblingAttack InvalidNodesAttack DropRouteMessageAttack InvalidDataAttack)

# for with_challenge in true false; do
#     for attack in ${attacks[@]}; do
#         for malicious_ratio in 0 0.1 0.5; do
#             cat > $directory/config.ini <<EOL
# [General]
# *.globalObserver.globalNodeList.maliciousNodeProbability = $malicious_ratio
# **.p2psipApp.withChallenge = $with_challenge

# include $directory/../simulations/attacks.ini
# EOL
#             $directory/../src/P2PSIPMANET -uCmdenv -c $attack -f $directory/config.ini | $directory/plotter.py $with_challenge graphs/${attack}_${malicious_ratio}_${with_challenge}.pdf
        done
    done
done
