/*
 * File:     a9p3.c
 * Author:   Lei Xie   100123800
 * Date:     2014/11/10
 * Version:  1.0
 *
 * Purpose:     The program which take a string then calling a function
 *              reverse_dup() to reverse the string and out put them
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Name:        reverse_dup
 * purpose:     it is a function which reverse the string using pointer
 * Output:      none
 * Returns:     return NULL means the string which need to be reverse is NULL
 *              return the return s_rev means return the reversed string
 * Assumptions: none
 * Bugs:        none
 * Notes:       the first while loop count the total char in the string
 *              the second while loop is to copy the char by pointer
 */
char *
reverse_dup(char * s)
{
    if (s == NULL)
        return NULL;
    int i = 0;
    int len;
    char *s_rev;
    s_rev = malloc(sizeof(*s));
    while (*s)
    {
        s++;
        i++;
        len = i;
    }
    while (i > 0)
    {
        s--;
        *s_rev = *s;
        s_rev++;
        --i;
    }
    s_rev = s_rev - len;
    return s_rev;
}

int
main(int argc, char * argv[])
{
    /* test 1 */
    char * s = "This is a string !";
    char * s_rev = reverse_dup(s);
    printf("|%s| reverses to |%s|\n\n", s, s_rev);

    /* test2 the string s1 is NULL */
    char * s1 = NULL;
    char * s1_rev = reverse_dup(s1);
    printf("|%s| reverses to |%s|\n\n", s1, s1_rev);

    /* test3 the string s2 is a space */
    char * s2 = " ";
    char * s2_rev = reverse_dup(s2);
    printf("|%s| reverses to |%s|\n\n", s2, s2_rev);

    /* test4 the string with spaces and tabs */
    char * s3 = " #$%   ^^sdasd       **   2    4";
    char * s3_rev = reverse_dup(s3);
    printf("|%s| reverses to |%s|\n\n", s3, s3_rev);

    /* test5 the string is very long */
    char * s4 = " aaaaaaaabbbbcdefghijklmnopqrse=tuvwxqqqqqqqqqqqqqqqqqqqq\
qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq\
qqqqqqqqqqqqqqqqqzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
wyz";
    char * s4_rev = reverse_dup(s4);
    printf("|%s| reverses to |%s|\n\n", s4, s4_rev);

    return EXIT_SUCCESS;
}
