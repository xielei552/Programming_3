/*
 * I have no time to comment
 * bugs:        can not handle "2/3/4 - 5" "1/5 / 6/-7" as an invailued input
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caculator.h"

int
main(int argc, char * argv[])
{
    Fraction_T lhs;
    Fraction_T rhs;
    Fraction_T result;
    int ret;
    char str[4];

    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s a/b operator c/d (4 arguements)\n",
                argv[0]);
        return EXIT_FAILURE;
    }
    lhs = new_Fraction(argv[1]);
    if (lhs == NULL)
    {
        fprintf(stderr, "%s should be two intagers or one\n", argv[1]);
        return EXIT_FAILURE;
    }
    rhs = new_Fraction(argv[3]);
    if (rhs == NULL)
    {
        fprintf(stderr, "%s should be two intagers or one\n", argv[3]);
        return EXIT_FAILURE;
    }
    ret = sscanf(argv[2], "%s", str);
    if (ret != 1)
    {
        fprintf(stderr, "the operator should be a char\n");
        return EXIT_FAILURE;
    }
    if (strlen(str) != 1)
    {
        fprintf(stderr, "the operator should be a char\n");
        return EXIT_FAILURE;
    }
    result = new_Fraction("1/1");

    switch (str[0])
    {
        case '+':
            add_Fraction(result, lhs, rhs);
            destroy_Fraction(&lhs);
            break;
        case '-':
            sub_Fraction(result, lhs, rhs);
            destroy_Fraction(&lhs);
            break;
        case '*':
            mul_Fraction(result, lhs, rhs);
            destroy_Fraction(&lhs);
            break;
        case 'x':
            mul_Fraction(result, lhs, rhs);
            destroy_Fraction(&lhs);
            break;
        case '/':
            div_Fraction(result, lhs, rhs);
            destroy_Fraction(&lhs);
            break;
        default:
            fprintf(stderr, "Invailed in put %s\n", argv[2]);
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
