#!/usr/bin/env bash

directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

$directory/../src/P2PSIPMANET -uCmdenv -c $1 -f $2  --seed-0-mt=`date +'%N'` ${@:3}
