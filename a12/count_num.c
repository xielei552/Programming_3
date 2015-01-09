/*
 * File:    count_num.c
 * Author:  Lei Xie
 * Date:    Dec 1, 2014
 * Version: 1.0
 *
 * Description: This file describes the interface to a number of functions.
 */
#include <stdio.h>
#include <stdlib.h>
#include "count_num.h"

/* static value */
static int evens = 0;
static int odds = 0;

/*
 * Name:        enter_anther_number
 * purpose:     it is a function which read an integer and print it, if it is
 *              an even number evens++ else odds++
 * Output:      none
 * Returns:     none
 * Assumptions: none
 * Bugs:        none
 */
void
enter_another_number(int c)
{
    printf("entering %d\n", c);
    if (c < 0)
        ;
    else if (c % 2 == 0)
        evens++;
    else
        odds++;
}

/*
 * Name:        how_many_evens
 * purpose:     it is a function which return the static value evens
 * Output:      none
 * Returns:     return the static value evens
 * Assumptions: none
 * Bugs:        none
 */
int
how_many_evens()
{
    return evens;
}

/*
 * Name:        how_many_odds
 * purpose:     it is a function which return the static value odds
 * Output:      none
 * Returns:     return the static value odds
 * Assumptions: none
 * Bugs:        none
 */
int
how_many_odds()
{
    return odds;
}

/*
 * Name:        reset_counters
 * purpose:     it is a function which reset static value evens and odds both
 *              to 0 and print "resetting!"
 * Output:      none
 * Returns:     none
 * Assumptions: none
 * Bugs:        none
 */
void
reset_counters()
{
    evens = 0;
    odds = 0;
    printf("resetting!\n");
}
