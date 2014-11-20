/*
 * Author: A. Nonymouse.
 * Date: 2038-10-09
 * File: a10p2.c
 * Version: 1.0
 *
 * A driver for a library of file statistics functions.
 * DO NOT MODIFY THIS FILE!
 * Your library must work with it AS GIVEN.
 */

#include <stdlib.h>
#include <stdio.h>
#include "FStats.h"

int
main(int argc, char * argv[])
{
    FILE * in;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <infile>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if ((in = fopen(argv[1], "r+")) == NULL)
    {
        fprintf(stderr, "%s: Unable to open %s for input. "
                "Quitting.\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }
    printf("\nStatistics for %s:\n", argv[1]);
    printf("\tCount of values: %12d\n", count_FStats(in));
    printf("\tSum of values: %12.2f\n", sum_FStats(in));
    printf("\tMean of values: %12.2f\n", mean_FStats(in));
    printf("\tVariance of values: %12.2f\n", variance_FStats(in));
    printf("\tStandard Deviation: %12.2f\n", stddev_FStats(in));
    printf("\tThe file is %ssorted.\n\n",
            sorted_FStats(in) ? "" : "not ");
    if (fclose(in) == EOF)
    {
        fprintf(stderr, "Error closing %s.\n", argv[1]);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
