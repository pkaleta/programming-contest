#!/bin/bash

while true
do
    python mal_gen.py > gen.in
    ./brute < gen.in > brute.out
    ./a.out < gen.in > my.out
    x=`diff my.out brute.out`
    if [ "$x" != "" ]
    then
        echo $x
        break;
    else
        echo "PASS"
        cat brute.out
        cat my.out
    fi
done
