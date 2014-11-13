/*
 * File:     a8p3.c
 * Author:   Lei Xie   100123800
 * Date:     2014/11/11
 * Version:  1.0
 *
 * Purpose:
 * The program read in a aquare matrix A the first input integer is n
 * in a loop value the input m to array and creat a transpose matrix A(T) 
 * then compare with each other if A = A(T) print out "it is symmetric "
 * for bonus addition #1 if the user input with a file ignore the prompts
 * for bonus addition #2 if the matrix A is orthogonal print 
 * "it is orthogonal matrix"
 * for the convience of the markers i will print out matrix A,
 * A(T), and P = A * A(T).
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Name:        func_compare
 * purpose:     it is a function which check if the matrix A is same as A(T) 
 * Output:      none
 * Returns:     return 0 means the two matrix are not the same, return 1 means
 *              they are same
 * Assumptions: none
 * Bugs:        none
 * Notes:       in a double for loop check if the matrix is the same
 */
#define MAX_INT_VALUE 1147483647 
int
func_compare(int n, int array1[][n], int array2[][n])
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            if (array1[i][j] != array2[i][j])
                return 0;
        }
    }
    return 1;
}

/*
 * Name:        func_orthogonal
 * purpose:     it is an function which check if the matrix P = A * A(T) is 
 *              a orthogonal matrix
 * Output:      none
 * Returns:     return 0 means it not orthogonal matrix, return 1 means it is
 *              orthogonal matrix
 * Assumptions: none
 * Bugs:        none
 * Notes:       when array3[i][i] != 1 or array3[i][j] != 0 return 0
 */
int
func_orthogonal(int n, int array3[][n])
{
    for (int i = 0; i <= n - 1; i++)
    {
        if (array3[i][i] != 1)
            return 0;
        for (int j = 0; j <= n - 1; j++)
        {
            if (i != j && array3[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

int
main(int argc, char * argv[])
{
    int n, m, ret, ret_tty;
    int i, j, k;
    int sum = 0;
    /* Bonus addition #1 is user input in file ignore the prompts */
    ret_tty = fileno(stdin);
    if (isatty(ret_tty))
    {
        printf("How many rows/columns in your matrix: ");
    }
    /* read in n */
    ret = scanf("%d", &n);
    /* Warnning if n over size */
    if (n > MAX_INT_VALUE || n < -MAX_INT_VALUE)
    {
        fprintf(stderr, "The number n is oversize!\n");
        return EXIT_FAILURE;
    }
    /* Warnning if n not exit or not a integer */
    if (ret == 0 || ret == EOF)
    {
        fprintf(stderr, "Invailed input Usage: n (n should be an integer)\n");
        return EXIT_FAILURE;
    }
    /* Warnning if n <= 0 */
    if (n <= 0)
    {
        fprintf(stderr, "n should be greater than 0 !\n");
        return EXIT_FAILURE;
    }
    int array1[n][n];
    int array2[n][n];
    int array3[n][n];
    /* Bonus addition #1 is user input in file ignore the prompts */
    if (isatty(ret_tty))
    {
        printf("Enter a matrix, row by row: ");
    }
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= n - 1; j++)
        {
            /* read in each integer */
            ret = scanf("%d", &m);
            /* warning if the m is over size */
            if (m > MAX_INT_VALUE || m < -MAX_INT_VALUE)
            {
                fprintf(stderr, "The number is oversize!\n");
                return EXIT_FAILURE;
            }
            /* Warnning if the m is not a integer */
            if (ret == 0)
            {
                fprintf(stderr, "The value in the matrix should be integer\n");
                return EXIT_FAILURE;
            }
            /* Warnning if m is not enough for n * n */
            if (ret == EOF)
            {
                fprintf(stderr, "the number of integer input is less than %d\n"
                        ,n * n);
                return EXIT_FAILURE;
            }
            array1[i][j] = m;
            array2[j][i] = m;
        }
    }
    /* Bouns addition #2 caculate matrix p = A * A(T) */
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= n - 1; j++)
        {
            for (k = 0; k <= n - 1; k++)
            {
                sum = sum + array1[i][k] * array2[k][j];
            }
            array3[i][j] = sum;
            sum = 0;
        }
    }
    /* in convenience of markers print out the shape of matrix A A(T) P */
    printf("Matrix A is:\n");
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= n - 1; j++)
        {
            printf("%d ", array1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matric A(T) is:\n");
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= n - 1; j++)
        {
            printf("%d ", array2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matrix P = A * A(T) is :\n");
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= n - 1; j++)
        {
            printf("%d ", array3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    /* call func_compare */
    ret = func_compare(n, array1, array2);
    if (ret == 0)
        printf("Your matrix is not symmetric!\n");
    if (ret == 1)
        printf("Your matrix is symmetirc!\n");
    /* Bonus addition #2 call func_orthogonal */
    ret = func_orthogonal(n, array3);
    if (ret == 0)
        printf("Your matrix is not orthogonal matrices!\n");
    if (ret == 1)
        printf("Your matrix is orthogonal matrices!\n");
    return EXIT_SUCCESS;
}

