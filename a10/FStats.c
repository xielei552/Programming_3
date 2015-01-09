/*
 * File:    FStats.c
 * Author:  Lei Xie
 * Date:    November 18, 2014
 * Version: 1.0
 *
 * Description: This file describes the interface to a number of functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FStats.h"


/*
 * Name:        count_FStats
 * purpose:     it is a function which read a file and count the double value
 *              in the file.
 * Output:      none
 * Returns:     return count means the number of values in the file
 * Assumptions: none
 * Bugs:        none
 */
int
count_FStats(FILE * in)
{
    rewind(in);
    int ret;
    double data;
    int count = 0;
    while (1)
    {
        ret = fscanf(in, "%lf", &data);
        if (ret != 1)
            break;
        count++;
    }
    return count;
}

/*
 * Name:        sum_FStats
 * purpose:     it is a function which read in a file and sum all the double
 *              value 
 * Output:      none
 * Returns:     return sum means return the sum value
 * Assumptions: none
 * Bugs:        none
 */
double
sum_FStats(FILE * in)
{
    rewind(in);
    int ret;
    double data;
    double sum = 0;
    while (1)
    {
        ret = fscanf(in, "%lf", &data);
        if (ret != 1)
            break;
        sum = sum + data;
    }
    return sum;
}

/*
 * Name:        mean_FStats
 * purpose:     it is a function which caculate the mean of all double value
 *              int the file by calling fuction sum_FStats and count_FStats
 * Output:      none
 * Returns:     return mean means return the value of mean
 * Assumptions: none
 * Bugs:        none
 */
double
mean_FStats(FILE * in)
{
    double mean, sum;
    int count;
    sum = sum_FStats(in);
    count = count_FStats(in);
    mean = sum / (count * 1.0);
    return mean;
}

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
double
variance_FStats(FILE * in)
{
    double mean;
    double data;
    double var = 0;
    int ret;
    int count;
    mean = mean_FStats(in);
    count = count_FStats(in);
    rewind(in);
    while (1)
    {
        ret = fscanf(in, "%lf", &data);
        if (ret != 1)
            break;
        var = var + (data - mean) * (data - mean);
    }
    var = var / (count * 0.1);
    return var;
}

/*
 * Name:        stddev_FStats
 * purpose:     it is a function which caculate the std deviation of all the
 *              data in file by calling function cariance_FStats
 * Output:      none
 * Returns:     return stddev means return the value of std devuation
 * Assumptions: none
 * Bugs:        none
 */
double
stddev_FStats(FILE * in)
{
    double var;
    double stddev;
    var = variance_FStats(in);
    stddev = (double)sqrt(var);
    return stddev;
}

/*
 * Name:        sorted_FStats
 * purpose:     it is a function which check the all data in the file
 * Output:      none
 * Returns:     return 0 means the data in the file is not sorted
 *              return 1 means the data in the file is sorted
 * Assumptions: none
 * Bugs:        none
 */
int sorted_FStats(FILE * in)
{
    double data, pre_data;
    int count = 0;
    int ret;
    rewind(in);
    while (1)
    {
        ret = fscanf(in, "%lf", &data);
        count++;
        if (ret != 1)
            break;
        if (count == 1)
        {
            pre_data = data;
            continue;
        }
        if (pre_data > data)
            return 0;
        pre_data = data;
    }
    return 1;
}
