#!/usr/bin/env bash

inFolder="${1:-in}"
outFolder="${2:-out}"
mkdir -p $outFolder

directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
mkdir -p graphs

attacks=(DropFindNodeAttack SiblingAttack InvalidNodesAttack DropRouteMessageAttack InvalidDataAttack ResolveToSelfAttack)
ratios=(0.0 0.1 0.2 0.3 0.4 0.5)
runs=10

for attack in ${attacks[@]}; do
    for malicious_ratio in ${ratios[@]}; do
        for with_challenge in true false; do
            for run in `seq $runs`; do
                $directory/plotter.py $with_challenge $outFolder/${attack}_${malicious_ratio}_${with_challenge}_${run}.pdf $inFolder/${attack}_${malicious_ratio}_${with_challenge}_${run}.log > /dev/null &
            done
            wait
        done
    done
done
