#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caculator.h"

struct my_struct
{
    int left_n;
    int right_n;
};

Fraction_T
new_Fraction(const char * str)
{
    Fraction_T new;
    int ret;
    new = malloc(sizeof(*new));
    if (new == NULL)
        return NULL;
    ret = sscanf(str, "%d/%d", &new->left_n, &new->right_n);
    if (ret == 1)
        new->right_n = 1;
    else if (ret == 2)
        ;
    else
        return NULL;
    return new;
}

int
print_Fraction(const Fraction_T f)
{
    printf("%d/%d\n", f->left_n, f->right_n);
    return 0;
}

int
destroy_Fraction(Fraction_T * f)
{
    if (f == NULL)
        return 1;
    else
        free(*f);
    return 0;
}

int
add_Fraction(Fraction_T result, const Fraction_T lhs, const Fraction_T rhs)
{
    if (lhs->right_n == 0 || rhs->right_n == 0)
    {
        fprintf(stderr, "b or d can not be 0\n");
        return EXIT_FAILURE;
    }
    printf("%d/%d + %d/%d is ", lhs->left_n, lhs->right_n, rhs->left_n,
            rhs->right_n);
    result->left_n = lhs->left_n * rhs->right_n + lhs->right_n * rhs->left_n;
    result->right_n = lhs->right_n * rhs->right_n;
    print_Fraction(result);
    return 0;
}
int
sub_Fraction(Fraction_T result, const Fraction_T lhs, const Fraction_T rhs)
{
    if (lhs->right_n == 0 || rhs->right_n == 0)
    {
        fprintf(stderr, "b or d can not be 0\n");
        return EXIT_FAILURE;
    }
    printf("%d/%d - %d/%d is ", lhs->left_n, lhs->right_n, rhs->left_n,
            rhs->right_n);
    result->left_n = lhs->left_n * rhs->right_n - lhs->right_n * rhs->left_n;
    result->right_n = lhs->right_n * rhs->right_n;
    print_Fraction(result);
    return 0;
}
int
mul_Fraction(Fraction_T result, const Fraction_T lhs, const Fraction_T rhs)
{
    if (lhs->right_n == 0 || rhs->right_n == 0)
    {
        fprintf(stderr, "b or d can not be 0\n");
        return EXIT_FAILURE;
    }
    printf("%d/%d * %d/%d is ", lhs->left_n, lhs->right_n, rhs->left_n,
            rhs->right_n);
    result->left_n = lhs->left_n * rhs->left_n;
    result->right_n = lhs->right_n * rhs->right_n;
    print_Fraction(result);
    return 0;
}
int
div_Fraction(Fraction_T result, const Fraction_T lhs, const Fraction_T rhs)
{
    if (lhs->right_n == 0 || rhs->left_n == 0)
    {
        fprintf(stderr, "b or c can not be 0\n");
        return EXIT_FAILURE;
    }
    printf("%d/%d / %d/%d is ", lhs->left_n, lhs->right_n, rhs->left_n,
            rhs->right_n);
    result->left_n = lhs->left_n * rhs->right_n;
    result->right_n = lhs->right_n * rhs->left_n;
    print_Fraction(result);
    return 0;
}
