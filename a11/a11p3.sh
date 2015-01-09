#! /bin/sh

# File:     a11p3.sh
# Author:   Lei Xie
# Purpose:  caculate the current minute and second if it fit
#           (13 * M + 3 * S) % 17 == 0 output "I like.." else ouput"I don't."
#           and continue untile find it
# Date:     Nov 25, 2014
# Version:  1.0
# Note:     None


for (( ; ; ))
do
    MIN=$(date +%M)
    SEC=$(date +%S)
    MM=`expr $MIN \* 13`
    SS=`expr $SEC \* 3`
    SUM=`expr $MM + $SS`
    MODU=`expr $SUM % 17`
    if test $MODU = 0
    then
        echo "I like the time ($MIN:$SEC)"
        break
    else
        echo "I don't like $MIN minutes and $SEC seconds."
        sleep 1
    fi
done
