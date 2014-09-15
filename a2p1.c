/*
 * File:     a2p1.c
 * Author:   Lei Xie   100123800
 * Date:     2014/09/15
 * Version:  1.0
 *
 * Purpose:
 * Tring to understand printf() function, and print out all the results
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("|%-9.5f| is field 9, precision 5, left justified\n", M_PI);
    printf("|%9.5f| is field 9, precision 5, right justified\n", M_PI);
    printf("|%9.f| is field 9, precision 0, right justified\n", M_PI);
    printf("|%.5f| is field 0, precision 5, right justified\n", M_PI);
    printf("|%9.5e| is field 9, precision 5, right justified\n", M_PI);
    printf("|%-9.5e| is field 9, precision 5, left justified\n", M_PI);
    printf("|%14.5e| is field 14, precision 5, right justified\n", M_PI);
    printf("|%-14.5e| is field 14, precision 5, left justified\n", M_PI);
    return EXIT_SUCCESS;
}
