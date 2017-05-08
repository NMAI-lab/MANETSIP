#!/usr/bin/env bash

outFolder="$1"
attack="$2"
malicious_ratio="$3"
with_challenge="$4"
run="$5"

directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
config="$directory/config_${attack}_${malicious_ratio}_${with_challenge}_${run}.ini"

cat > $config <<EOL
[General]
*.globalObserver.globalNodeList.maliciousNodeProbability = $malicious_ratio
**.p2psipApp.withChallenge = $with_challenge

include $directory/../simulations/attacks.ini
EOL

until ($directory/run.sh $attack $config > $outFolder/${attack}_${malicious_ratio}_${with_challenge}_${run}.log); do
    echo "${attack}_${malicious_ratio}_${with_challenge}_${run} failed; trying again."
done

rm $config
