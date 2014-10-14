/*
 * File:     a1p1.c
 * Author:   Lei Xie   100123800
 * Date:     2014/09/10
 * Version:  1.0
 *
 * Purpose:
 * input a number N and find the total N number of prime numbers 
 * then print out. This program can run large numbers. in order to
 * use the result in the future, if you input a invalid number
 * the program will give error meesage, usage and exit
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Name:        prime
 * purpose:     to judge that if the numer is a prime
 * returns:     0 on false, 1 on true the return will be 
 *              used in the next function
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

/*
 * Name:        prime_list
 * purpose:     if the number is a prime print out keep going
 *              if the number is not a prime do nothing and keep going
 * Output:      the number which is a prime
 * Returns:     none
 * Assumptions: none
 * Bugs:        none
 * Notes:       go through the function prime(),if the number is a prime
 *              print out, if not keep going until the n == 0
 */
void
prime_list(long int n)
{
    long int i = 2;
    while (n)
    {
        if (i == 2)
        {
            printf("2\n");
            i++;
            n--;
        }
        else if (prime(i))
        {
            printf("%ld\n", i);
            n--;
            i = i + 2;
        }
        else
        {
            i = i + 2;
        }
    }
}


int
main(int argc, char* argv[])
{
    int ret;
    long int number;
    if (argc != 2)
    {
        fprintf(stderr, "Invalid argument!\n");
        fprintf(stderr, "Usage: a3p1 <number of primes to output>\n");
        return EXIT_FAILURE;
    }
    ret = sscanf(argv[1], "%ld", &number);
    if (number < 1)
    {
        fprintf(stderr, "Invalid argument!\n");
        fprintf(stderr, "Usage: a3p1 <number of primes to output>\n");
        return EXIT_FAILURE;
    }
    /*if the sscanf() is invalid error message and exit*/
    else if (ret != 1)
    {
        fprintf(stderr, "Invalid argument!\n");
        fprintf(stderr, "Usage: a3p1 <number of primes to output>\n");
        return EXIT_FAILURE;
    }
    else
    {
        /*run the function prime_list*/
        prime_list(number);
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}

