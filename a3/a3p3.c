/*
 * File:     a3p3.c
 * Author:   Lei Xie   100123800
 * Date:     2014/09/24
 * Version:  1.0
 *
 * Purpose:
 * if the user give a filename, this program will open the file
 * and reads the number of lower case letters, upper case letters,
 * digits and white-space characters, then print out them, and the
 * program can exit when user type --quit 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ARRAY_SIZE 81

/*
 * Name:        checkerfile
 * purpose:     to find the number of lower case letters, upper case letters
 *              digits and white-space characters, then print out them
 * Output:      the number of lower case letters, upper case letters,digits 
 *              and white-space characters
 * Returns:     none
 * Assumptions: none
 * Bugs:        none
 * Notes:       lower, upper, digits, white_space are the counter to cout 
 *              the time the charaters shows up
 */
void
checkerfile(FILE *fin)
{
    char c;
    int lower,upper,digits,white_space;
    lower = 0;
    upper = 0;
    digits = 0;
    white_space = 0;
    while (1)
    {
        c = getc(fin);
        if (c == EOF)
        {
            break;
        }
        else if (islower(c))
        {
            lower++;
            continue;
        }
        else if (isupper(c))
        {
            upper++;
            continue;
        }
        else if (isdigit(c))
        {
            digits++;
            continue;
        }
        else if (isspace(c))
        {
            white_space++;
            continue;
        }
    }
    printf("the number of lower case letter : %d\n", lower);
    printf("the number of upper case letter : %d\n", upper);
    printf("the number of digits : %d\n", digits);
    printf("the number of white-space characters : %d\n", white_space);
}

int
main(int argc, char* argv[])
{
    FILE *fin;
    char str[ARRAY_SIZE];
    char str1[ARRAY_SIZE];
    while (1)
    {
        printf("Please input a flie name:\n");
        fgets(str, ARRAY_SIZE, stdin);
        /*if the file name is too long exit*/
        if (strlen(str) == ARRAY_SIZE - 1)
        {
            fprintf(stderr, "The file name is too long, EXIT!!!\n");
            return EXIT_FAILURE;
        }
        /*throw away the '\n' at the end of string*/
        sscanf(str, "%s%*[\n]", str1);
        fin = fopen(str1, "r");
        /*if user type --quit exit the program*/
        if (strcmp(str1, "--quit") == 0)
        {
            return EXIT_SUCCESS;
        }
        /*if the filename is not exist, return error message*/
        if (fin == NULL)
        {
            fprintf(stderr, "Could not open %stry agian\n", str);
            continue;
        }
        else
        {
            checkerfile(fin);
        }
        fclose(fin);

    }
    return EXIT_SUCCESS;
}
