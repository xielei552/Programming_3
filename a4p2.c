/*
 * File:     a4p2.c
 * Author:   Lei Xie   100123800
 * Date:     2014/10/01
 * Version:  1.0
 *
 * Purpose:rogram which takes exactly two command line arguments,
 * m and p . It will test whether or not m is a primitive p-th 
 * root of unity
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

/* define the max int value */
#define MAX_VALUE 2147483647

/*
 * Name:        prime
 * purpose:     to judge that if the numer is a prime
 * returns:     0 on false, 1 on true the return will be 
 *              used in the main function
 * Assumptions: none
 * Bugs:        none
 * Notes:       this function is in order to judge if the number 
 *              is a prime
 */
int
prime(long int x)
{
    int i;
    if (x == 2)
        return 1;
    else if (x == 3)
        return 1;
    else if (x == 5)
        return 1;
    else if (x%2 == 0)
    {
        return 0;
    }
    else if (x%3 == 0)
    {
        return 0;
    }
    else if (x%5 == 0)
    {
        return 0;
    }
    else
    {
        for (i = 2; i <= (int)sqrt(x); i++)
        {
            if (x%i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int
main(int argc, char *argv[])
{
    uint64_t square_m;
    long int p,m,i;
    /* if the input is invalued print out usage and warning */
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s number_m number_p\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (sscanf(argv[1], "%ld", &m) != 1)
    {
        fprintf(stderr, "Usage: %s number_m number_p\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (sscanf(argv[2], "%ld", &p) != 1)
    {
        fprintf(stderr, "Usage: %s number_m number_p\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (m >= p)
    {
        fprintf(stderr, "Invalued input: number_m less than number_p\n");
        return EXIT_FAILURE;
    }
    if ((prime(p)) == 0)
    {
        fprintf(stderr,"the number_p '%ld' is not a prime\n", p);
        return EXIT_FAILURE;
    }
    square_m = 1;
    for (i = 1; i <= p - 1; i++)
    {
        square_m = square_m * m;
        if (square_m % p == 1)
        {
            /* if the m ^ (p - 1) % p == 1 */
            if (i == p - 1)
            {
                printf("%ld is a primitive %" PRIu64 "", m, (p - 1));
                printf("-th root of untiy modulo %" PRIu64 "\n", p);
                return EXIT_SUCCESS;
            }
            else
            {
                printf("%ld is not a primitive %" PRIu64 "", m, (p - 1));
                printf("-th root of untiy modulo %" PRIu64 "\n", p);
                return EXIT_SUCCESS;
            }
        }
        /* in case of overflow */
        else if (square_m >= MAX_VALUE)
        {
            square_m = square_m % p;
        }
    }
    return EXIT_SUCCESS;
}
