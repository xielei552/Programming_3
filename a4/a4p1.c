/*
 * File:     a4p1.c
 * Author:   Lei Xie   100123800
 * Date:     2014/09/30
 * Version:  1.0
 *
 * Purpose:
 * the program will read integers from stdin
 * until EOF or invalid input. The program will then
 * output the second smallest number in the input.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INBUF_SIZE 10000000000000

int
main(int argc, char *argv[])
{
    long int a;
    int counter;
    long int min,sec_min;

    counter = 0;
    /* read int form stdin until others char */
    while (scanf("%ld", &a) == 1)
    {
        /* in case if the number is too large */
        if (a > INBUF_SIZE)
        {
            fprintf(stderr,"there is one number over the size\n");
            return EXIT_FAILURE;
        }
        /* find the second smallest one */
        else
        {
            if (counter == 0)
            {
                min = a;
                sec_min = a;
                counter++;
            }
            else if (counter == 1)
            {
                if (min > a)
                {
                    min = a;
                    counter++;
                }
                else
                {
                    sec_min = a;
                    counter++;
                }
            }
            else
            {
                if (min >= a)
                {
                    sec_min = min;
                    min = a;
                    counter++;
                }
                else if (sec_min > a && min <= a)
                {
                    sec_min = a;
                    counter++;
                }
            }
        }
    }
    /* if the number of int we read in is less than 2 warning */
    if (counter == 1 || counter == 0)
    {
        fprintf(stderr, "Did not have the second smallest value\n");
        return EXIT_FAILURE;
    }
    else
    {
        printf("%ld\n", sec_min);
    }
    return EXIT_SUCCESS;
}

