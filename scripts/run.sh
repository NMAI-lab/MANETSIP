#!/usr/bin/env bash

set -x

cd ../simulations
../src/P2PSIPMANET -uCmdenv -c $1 -f $2 ${@:3}
