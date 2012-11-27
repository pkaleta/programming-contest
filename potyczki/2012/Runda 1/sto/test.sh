#!/bin/bash

DIR=testySTO

for f in `ls $DIR/*.in`; do
    filename=$(basename "$f")
    filename="${filename%.*}"
    ./a.out < $DIR/$filename.in > moj.out
    diff moj.out $DIR/$filename.out
done
