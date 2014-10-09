/*
 * File:     a5p3.c
 * Author:   Lei Xie   100123800
 * Date:     2014/10/07
 * Version:  1.0
 *
 * Purpose:
 * program is one that reads from stdin and writes to stdout and
 * analyze the length of “words” of the input. then output the type of 
 * word lenth and the times it showed up. then out put the average word
 * lenth.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TYPE_LEN 26

int
main(int argc, char *argv[])
{
    int c;
    int len = 0, num_word = 0;
    int a[TYPE_LEN] = {0};
    int i;
    double avr = 0, counter = 0;
    while (1)
    {
        c = fgetc(stdin);
        /* if read to the EOF break the loop */
        if (c == EOF)
            break;
        /* if not a white-space char */
        if (isspace(c) == 0)
        {
            len++;
            /* the counter is to sum the total chars */
            counter++;
        }
        else
        {
            /* if the lenth over 25 */
            if (len > TYPE_LEN)
            {
                a[TYPE_LEN]++;
                num_word++;
                len = 0;
            }
            else if (len > 0 && len <= TYPE_LEN)
            {
                a[len - 1]++;
                num_word++;
                len = 0;
            }
            else
                ;
        }
    }
    /* out put the information needed */
    for (i = 0; i < TYPE_LEN - 1; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        else
        {
            printf("Word of lenth%5d: %3d\n", i + 1, a[i]);   
        }
    }
    /* the word lenth over 25 in other case */
    if (a[TYPE_LEN] > 0)
    {
        printf("Word of lenth > 25: %3d\n", a[TYPE_LEN]);
    }
    /* if no word do nothing exit */
    if (num_word == 0)
        return EXIT_SUCCESS;
    /* ouput the average */
    else
    {
        avr = counter / num_word;
        printf("Overall average word lenth: %.2f\n", avr);
    }
    return EXIT_SUCCESS;

}
