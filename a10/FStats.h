/*
 * File:    FStats.h
 * Author:  Lei Xie
 * Date:    November 18, 2014
 * Version: 1.0
 *
 * Description: This file describes the interface to a number of functions.
 */
#ifndef FSTATS
#define DSTATS

/*
 * Name:        count_FStats
 * purpose:     it is a function which read a file and count the double value
 *              in the file.
 * Output:      none
 * Returns:     return count means the number of values in the file
 * Assumptions: none
 * Bugs:        none
 */
int count_FStats(FILE *);

/*
 * Name:        sum_FStats
 * purpose:     it is a function which read in a file and sum all the double
 *              value 
 * Output:      none
 * Returns:     return sum means return the sum value
 * Assumptions: none
 * Bugs:        none
 */
double sum_FStats(FILE *);

/*
 * Name:        mean_FStats
 * purpose:     it is a function which caculate the mean of all double value
 *              int the file by calling fuction sum_FStats and count_FStats
 * Output:      none
 * Returns:     return mean means return the value of mean
 * Assumptions: none
 * Bugs:        none
 */
double mean_FStats(FILE *);

/*
 * Name:        varience_FStats
 * purpose:     it is a function which caculate the cariance of the all the 
 *              double data in the file by calling function mean_FStats and
 *              count_FStats
 * Output:      none
 * Returns:     return var means return the value of variance
 * Assumptions: none
 * Bugs:        none
 */
double variance_FStats(FILE *);

/*
 * Name:        stddev_FStats
 * purpose:     it is a function which caculate the std deviation of all the
 *              data in file by calling function cariance_FStats
 * Output:      none
 * Returns:     return stddev means return the value of std devuation
 * Assumptions: none
 * Bugs:        none
 */
double stddev_FStats(FILE *);

/*
 * Name:        sorted_FStats
 * purpose:     it is a function which check the all data in the file
 * Output:      none
 * Returns:     return 0 means the data in the file is not sorted
 *              return 1 means the data in the file is sorted
 * Assumptions: none
 * Bugs:        none
 */
int sorted_FStats(FILE *);

#endif
