#!/usr/bin/env bash

inFolder="${1:-in}"
outFolder="${2:-out}"
mkdir -p $outFolder

for file in $inFolder/*_false_*; do
    grep  -o -E '^\[Chord::READY\] 10\.0\.0\.[0-9]{1,3}' $file | sort | uniq | wc -l > $outFolder/`basename $file`
    grep '^P2PSIPTestApp: Resolve failed' $file | wc -l >> $outFolder/`basename $file`
    echo 0 >> $outFolder/`basename $file`
    grep '^P2PSIPTestApp: Resolve success .* wrong data$' $file | wc -l >> $outFolder/`basename $file`
done

for file in $inFolder/*_true_*; do
    grep  -o -E '^\[Chord::READY\] 10\.0\.0\.[0-9]{1,3}' $file | sort | uniq | wc -l > $outFolder/`basename $file`
    grep '^P2PSIPTestApp: Resolve failed' $file | wc -l >> $outFolder/`basename $file`
    grep '^P2PSIPTestApp: Challenge failed' $file | wc -l >> $outFolder/`basename $file`
    grep '^P2PSIPTestApp: Challenge success' $file | wc -l >> $outFolder/`basename $file`
done
