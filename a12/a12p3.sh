#! /bin/sh

# File:     a12p3.sh
# Author:   Lei Xie
# Purpose:  the shell program find the file in /usr/bin count the sum of 
#           file and sum of text file, print the sum of file, sum of text
#           file and precent of script file
# Date:     Dec 3, 2014
# Version:  1.0
# Note:     None

total=0
text=0
find /usr/bin | \
(
    while read line
    do
        total=`expr $total + 1`
        if [ $(file $line | grep -c text) = 1 ]
        then
            text=`expr $text + 1`
        else
            :
        fi
    done
    echo I am using GNU/Linux 2.6.32, 64-bit version
    echo There are $total file in /usr/bin
    echo There are $text text file in /usr/bin
    script=`expr $total - $text`
    percent=$( echo $script \* 100 / $total | bc)
    echo $percent % file is script file
)
