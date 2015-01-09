/*
 * File:    count_num.h
 * Author:  Lei Xie
 * Date:    Dec 1, 2014
 * Version: 1.0
 *
 * Description: This file describes the interface to a number of functions.
 */
#ifndef COUNT_NUM
#define COUNT_NUM

/*
 * Name:        enter_anther_number
 * purpose:     it is a function which read an integer and print it, if it is
 *              an even number evens++ else odds++
 * Output:      none
 * Returns:     none
 * Assumptions: none
 * Bugs:        none
 */
void enter_another_number(int);

/*
 * Name:        how_many_evens
 * purpose:     it is a function which return the static value evens
 * Output:      none
 * Returns:     return the static value evens
 * Assumptions: none
 * Bugs:        none
 */
int how_many_evens(void);

/*
 * Name:        how_many_odds
 * purpose:     it is a function which return the static value odds
 * Output:      none
 * Returns:     return the static value odds
 * Assumptions: none
 * Bugs:        none
 */
int how_many_odds(void);

/*
 * Name:        reset_counters
 * purpose:     it is a function which reset static value evens and odds both
 *              to 0 and print "resetting!"
 * Output:      none
 * Returns:     none
 * Assumptions: none
 * Bugs:        none
 */
void reset_counters(void);

#endif
