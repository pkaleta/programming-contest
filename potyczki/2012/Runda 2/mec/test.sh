#!/bin/bash

DIR=tests

for f in `ls $DIR/*.in`; do
    filename=$(basename "$f")
    filename="${filename%.*}"
    time ./a.out < $DIR/$filename.in > moj.out
    diff moj.out $DIR/$filename.out
done
