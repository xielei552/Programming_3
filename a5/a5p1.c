/*
 * File:     a5p1.c
 * Author:   Lei Xie   100123800
 * Date:     2014/10/04
 * Version:  1.0
 *
 * Purpose:
 * program which accepts two strings as command-line arguments the first
 * number is the number of characters of the search string which match, and
 * the second number is how many characters from the right end of the text 
 * to go backwards then output longest words matching and the matching
 * position 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200
int
main(int argc, char *argv[])
{
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int i,j,k;
    int counter,position,num_match;
    int len_str1,len_str2;
    /* not enough arguements warning */
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s string search_string\n", argv[0]);
        return EXIT_FAILURE;
    }
    strncpy(str1, argv[1], MAX_SIZE);
    strncpy(str2, argv[2], MAX_SIZE);
    len_str1 = strlen(str1);
    len_str2 = strlen(str2);
    /* warrning if the argument is too long */
    if (len_str1 >= MAX_SIZE || len_str2 >= MAX_SIZE)
    {
        fprintf(stderr, "the string you type in is too long! Try again\n");
        return EXIT_FAILURE;
    }
    counter = 0;
    num_match = 0;
    /* first for loop is changing the string position */
    for (i = 0; len_str1 > i; i++)
    {
        k = i;
        /* second for loop change the search string position */ 
        for (j = 0; j < len_str2; j++)
        {
            if (str1[k] == str2[j])
            {
                counter++;
                k++;
            }
            else
                break;
        }
        /* if matched copy the position in string and num_char matched */ 
        if (counter >= num_match)
        {
            num_match = counter;
            position = len_str1 - i;
            counter = 0;
        }
        else
            counter = 0;
    }
    if (num_match == 0)
    {
        printf("%d;%c\n", num_match, str2[0]);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("%d;%d\n", num_match, position);
    }
    return EXIT_SUCCESS;
}
