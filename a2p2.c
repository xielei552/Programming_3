/*
 * File:     a2p2.c
 * Author:   Lei Xie   100123800
 * Date:     2014/09/11
 * Version:  1.0
 *
 * Purpose:
 * a program which reads in a sequence of integers, does some calculations,
 * and outputs some statistics. Specifically, your program reads in an
 * integer, which tells it how many ore integers to read in. Then,
 * it reads that many integers. Finally, it outputs the maximum
 * number read in, the minimum number read in, and the average of the numbers 
 * read in to two decimal places 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int n,i,MAX,MIN,number;
    double avr,sum;
    printf ("How many numbers will you give me? ");
    /*Error checking*/
    if (scanf ("%d", &n) == 1)
    {
        printf ("Great, please enter those ");
        printf ("%d", n);
        printf (" numbers: ");

        MAX = 0;
        avr = 0;
        sum = 0;
        for (i=1; i <= n; i++)
        {
            /*Error checking*/
            if(scanf("%d", &number) == 1)
            {
                if (i == 1)
                {
                    MIN = number;
                }
                /*get maximum number*/
                MIN = ((MIN < number) ? MIN : number);
                /*get minimum number*/
                MAX = ((MAX > number) ? MAX : number);
                sum = sum + number; 

            }
            else 
            { 
                fprintf(stderr, "Invalid input. Try again.\n");
                return EXIT_FAILURE;
            }
        }
        /*caculate average*/
        avr = sum / n;
        printf("The minium, mumber was ");
        printf("%d\n", MIN);
        printf("The maximum number was ");
        printf("%d\n", MAX);
        printf("The average was ");
        printf("%.2f\n", avr);
    }
    else 
    {
        fprintf(stderr, "Invalid input. Try again.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
