#!/bin/sh

export PATH=$PATH:.

rm -rf in

for f in test1 test2 fileempty long-char long-number nonexist
do
    printf "\ncp $f in\n"
    cp $f in

    printf "\na4p3 in out\n"
    a4p3 in out

    printf "\ncat in\n"
    cat in

    printf "\ncat out\n"
    cat out

    printf "\nod -cb in\n"
    od -cb in

    printf "\nod -cb out\n\n"
    od -cb out

    printf "\nrm -f in out\n"
    rm -f in out
done
