#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_INT_VALUE 1147483647 
int
func_compare(int n, int array1[][n], int array2[][n])
{
    for(int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            if (array1[i][j] != array2[i][j])
                return 0;
        }
    }
    return 1;
}

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
main(int argc, char *argv[])
{
    int n,m,ret,ret_tty;
    int i,j,k;
    int sum = 0;
    ret_tty = fileno(stdin);
    if (isatty(ret_tty))
    {
        printf("How many rows/columns in your matrix: ");
    }
    ret = scanf("%d", &n);
    if (ret == 0 || ret == EOF)
    {
        fprintf(stderr, "Invailed input Usage: n (n should be an integer)\n");
        return EXIT_FAILURE;
    }
    if (n <= 0)
    {
        fprintf(stderr,"n should be greater than 0 !\n");
        return EXIT_FAILURE;
    }
    int array1[n][n];
    int array2[n][n];
    int array3[n][n];
    if (isatty(ret_tty))
    {
        printf("Enter a matrix, row by row: ");
    }
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= n - 1; j++)
        {
            ret = scanf("%d", &m);
            if (m > MAX_INT_VALUE || m < -MAX_INT_VALUE)
            {
                fprintf(stderr, "The number is oversize!\n");
                return EXIT_FAILURE;
            }
            if (ret == 0)
            {
                fprintf(stderr, "The value in the matrix should be integer\n");
                return EXIT_FAILURE;
            }
            if (ret == EOF)
            {
                fprintf(stderr, "the number of integer input is less than %d\n",n * n);
                return EXIT_FAILURE;
            }
            array1[i][j] = m;
            array2[j][i] = m;
        }
    }
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
    /* this is a test */
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

    ret = func_compare(n, array1, array2);
    if (ret == 0)
        printf("Your matrix is not symmetric!\n");
    if (ret == 1)
        printf("Your matrix is symmetirc!\n");
    ret = func_orthogonal(n,array3);
    if (ret == 0)
        printf("Your matrix is not orthogonal matrices!\n");
    if (ret == 1)
        printf("Your matrix is orthogonal matrices!\n");
    return EXIT_SUCCESS;
}

