#! /bin/sh

# File:     a12p2.sh
# Author:   Lei Xie
# Purpose:  the shell program read in a float number "money" to buy the less
#           stamps using the money there are $2.00 $0.39 $0.05
#           $0.01 4 kinds of stamps                 
# Date:     Dec 2, 2014
# Version:  1.0
# Note:     None

echo -n "How much money do you have?"
read money
if test $money \< 0
then
    echo the money should more than 0
else
    echo
    echo You should receive

# the $2.00 stamp
    stamp1=$( echo $money / 2.00 | bc )
    if test $stamp1 = 0
    then
        :
    else
        if test $stamp1 = 1
        then
            echo "      $stamp1 \$2.00 stamp"
        else
            echo "      $stamp1 \$2.00 stamps"
        fi
    fi

# the $0.39 stamp
    cost=$( echo $stamp1 \* 2.00 | bc )
    rest=$( echo $money - $cost | bc )
    stamp2=$( echo $rest / 0.39 | bc )
    if test $stamp2 = 0
    then
        :
    else
        if test $stamp2 = 1
        then
            echo "      $stamp2 \$0.39 stamp"
        else
            echo "      $stamp2 \$0.39 stamps"
        fi
    fi

# the $0.05 stamp
    cost=$( echo $stamp2 \* 0.39 | bc )
    rest=$( echo $rest - $cost | bc )
    stamp3=$( echo $rest / 0.05 | bc )
    if test $stamp3 = 0
    then
        :
    else
        if test $stamp3 = 1
        then
            echo "      $stamp3 \$0.05 stamp"
        else
            echo "      $stamp3 \$0.05 stamps"
        fi
    fi

# the $0.01 stamp
    cost=$( echo $stamp3 \* 0.05 | bc )
    rest=$( echo $rest - $cost | bc )
    stamp4=$( echo $rest / 0.01 | bc )
    if test $stamp4 = 0
    then
        :
    else
        if test $stamp4 = 1
        then
            echo "      $stamp4 \$0.01 stamp"
        else
            echo "      $stamp4 \$0.01 stamps"
        fi
    fi
fi
