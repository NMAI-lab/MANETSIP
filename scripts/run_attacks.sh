#!/usr/bin/env bash

directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
mkdir -p graphs

attacks=(DropFindNodeAttack SiblingAttack InvalidNodesAttack DropRouteMessageAttack InvalidDataAttack)

for with_challenge in true false; do
    for attack in ${attacks[@]}; do
        for malicious_ratio in 0 0.1 0.5; do
            cat > $directory/config.ini <<EOL
[General]
*.globalObserver.globalNodeList.maliciousNodeProbability = $malicious_ratio
**.p2psipApp.withChallenge = $with_challenge

include $directory/../simulations/attacks.ini
EOL
            $directory/../src/P2PSIPMANET -uCmdenv -c $attack -f $directory/config.ini | $directory/plotter.py $with_challenge graphs/${attack}_${malicious_ratio}_${with_challenge}.pdf
        done
    done
done
