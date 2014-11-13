
/*
 * File:     a9p1.c
 * Author:   Lei Xie   100123800
 * Date:     2014/11/9
 * Version:  1.0
 *
 * Purpose:     The prpgram which will take each function fi() in mystery.o
 *              and find the x between 0 and PI 
 *              but the time of calling fi() function is limited
 *              if the times of calling is over the max_evals it will print
 *              different message
 */
#include "mystery.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI    3.14159265358979323846263433
#endif

/*
 * Name:        find_zero
 * purpose:     it is a function which can find a x between 0 and PI when the
 *              fi(x) == 0 or <= tolerance
 * Output:      none
 * Returns:     return 0 means success to fine the number x which fi(x) <= 
 *              tolerance
 *              return 1 means can not find such x
 * Assumptions: none
 * Bugs:        none
 */
int
find_zero(double (*f)(double), double x_min, double x_max, double tol,
        int max_evals, double * desired_x, int * num_evals)
{
    double y1, y2, mid, f_mid;
    int i = 0;
    int count = 0;
    y1 = f(x_min);
    count++;
    y2 = f(x_max);
    count++;
    for (i = 1 + count; i <= max_evals; i++)
    {
        /* when fi(x1) == fi(x2) == 0 */ 
        if (y1 == y2 && y1 == 0)
        {
            *desired_x = x_min;
            *num_evals = i;
            return 0;
        }
        /* when fi(x1) > fi(x2) */
        else if (y1 > y2)
        {
            mid = (x_min + x_max) / 2;
            f_mid = f(mid);
            if (fabs(f_mid) <= tol)
            {
                *num_evals = i;
                *desired_x = mid;
                return 0;
            }
            if (f_mid > 0)
            {
                x_min = mid;
                y1 = f_mid;
            }
            else if (f_mid < 0)
            {
                x_max = mid;
                y2 = f_mid;
            }
        }
        /* when fi(x1) < fi(x2) */
        else if (y1 < y2)
        {
            mid = (x_min + x_max) / 2;
            f_mid = f(mid);
            if (fabs(f_mid) <= tol)
            {
                *num_evals = i;
                *desired_x = mid;
                return 0;
            }
            if (f_mid > 0)
            {
                x_max = mid;
                y2 = f_mid;
            }
            else if (f_mid < 0)
            {
                x_min = mid;
                y1 = f_mid;
            }
        }
    }
    return 1;
}
int
main(int argc, char * argv[])
{
    double tol;
    int max_tries, ret;
    double x;
    int evals = 0;

    /* warrning if not enough argument */
    if (argc != 3)
    {
        fprintf(stderr, "Invalid input, Usgee %s tol max_tries\n", argv[0]);
        return EXIT_FAILURE;
    }

    ret = sscanf(argv[1], "%lf", &tol);

    /* warnning if can not read a double value form argv[1] */
    if (ret != 1)
    {
        fprintf(stderr, "Invalid input, Usgee %s tol max_tries\n", argv[0]);
        return EXIT_FAILURE;
    }
    /* warnning if tol less than 0 */
    if (tol < 0)
    {
        fprintf(stderr, "The number of tol should not be less than 0\n");
        return EXIT_FAILURE;
    }


    sscanf(argv[2], "%d", &max_tries);

    /* warnning if can not read a double value form argv[2] */
    if (ret != 1)
    {
        fprintf(stderr, "Invalid input, Usgee %s tol max_tries\n", argv[0]);
        return EXIT_FAILURE;
    }
    /* warnning if max_tries less equal than 0 */
    if (max_tries <= 0)
    {
        fprintf(stderr, "The number of tol should be greater than 0\n");
        return EXIT_FAILURE;
    }

    /* print format */
    printf("function        tollerance        evals    found?   x\n");
    printf("-------------------------------------------------------------\n");

    /* test f1() */
    ret = find_zero(f1, 0.0, M_PI, tol, max_tries, &x, &evals);

    if (ret == 1)
        printf("f1              %-17.e %-8d no       ?\n", tol, max_tries);
    if (ret == 0)
        printf("f1              %-17.e %-8d yes      %-.9lf\n", tol, evals, x);

    /* test f2() */
    ret = find_zero(f2, 0.0, M_PI, tol, max_tries, &x, &evals);
    if (ret == 1)
        printf("f2              %-17.e %-8d no       ?\n", tol, max_tries);
    if (ret == 0)
        printf("f2              %-17.e %-8d yes      %-.9lf\n", tol, evals, x);

    /* test f3() */
    ret = find_zero(f3, 0.0, M_PI, tol, max_tries, &x, &evals);
    if (ret == 1)
        printf("f3              %-17.e %-8d no       ?\n", tol, max_tries);
    if (ret == 0)
        printf("f3              %-17.e %-8d yes      %-.9lf\n", tol, evals, x);

    /* test f4() */
    ret = find_zero(f4, 0.0, M_PI, tol, max_tries, &x, &evals);
    if (ret == 1)
        printf("f4              %-17.e %-8d no       ?\n", tol, max_tries);
    if (ret == 0)
        printf("f4              %-17.e %-8d yes      %-.9lf\n", tol, evals, x);

    /* test f5() */
    ret = find_zero(f5, 0.0, M_PI, tol, max_tries, &x, &evals);
    if (ret == 1)
        printf("f5              %-17.e %-8d no       ?\n", tol, max_tries);
    if (ret == 0)
        printf("f5              %-17.e %-8d yes      %-.9lf\n", tol, evals, x);

    /* test f6() */
    ret = find_zero(f6, 0.0, M_PI, tol, max_tries, &x, &evals);
    if (ret == 1)
        printf("f6              %-17.e %-8d no       ?\n", tol, max_tries);
    if (ret == 0)
        printf("f6              %-17.e %-8d yes      %-.9lf\n", tol, evals, x);

    return EXIT_SUCCESS;
}
