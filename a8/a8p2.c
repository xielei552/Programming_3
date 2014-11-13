#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define     MAX_LINE_LENGTH 80
int
main(int argc, char *argv[])
{
    FILE *infile;
    if (argc != 2)
    {
        fprintf(stderr, "Usage:  %s <infile>\n", argv[0]);
        return EXIT_FAILURE;
    }
    infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        fprintf(stderr, "%s: unable to open '%s' for reading.\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }
    char str1[MAX_LINE_LENGTH];
    int length;
    while (1)
    {
        if (fgets(str1, MAX_LINE_LENGTH + 2, infile) == NULL)
            return EXIT_SUCCESS;
        length = strlen(str1);
        if (str1[length - 1] != '\n')
            fprintf(stderr, "Line too long (> %d chars)\n", MAX_LINE_LENGTH);
        for (int i = 0; i <= length - 1; i++)
        {
            if (ispunct(str1[i]) != 0 && str1[i] != '#' && str1[i] != '.' && str1[i] != '"' && str1[i] != '&' && str1[i] != '_' && str1[i] != '*')
            {
                if (str1[i] == '/' && str1[i + 1] == '*')
                {
                    for (int j = i; j <= length - 2; j++)
                    {
                        if (str1[j] == '*' && str1[j + 1] == '/')
                        {
                            i = j + 2;
                        }
                    }
                }
                else if (str1[i] == '/' && str1[i + 1] == '/')
                {
                    break;
                }
                else if (str1[i] == '(' && str1[i + 1] == '"')
                {
                    printf("%c\n", str1[i]);
                    printf("%c", str1[i + 1]);
                    for (int k = i + 2; k <= length - 1; k++)
                    {
                        if (str1[k] == '"')
                        {
                            printf("%c\n", str1[k]);
                            i = k + 1;
                            break;
                        }
                        else
                            printf("%c", str1[k]);
                    }
                }
                else
                {
                        printf("%c\n", str1[i]);
                        i++;
                }
            }
            if (isspace(str1[i]) != 0)
                continue;
            else
            {
                if (str1[i + 1] == '"')
                    ;
                else if (ispunct(str1[i + 1]) != 0 && str1[i + 1] != '.' && str1[i + 1] != '_')
                    printf("%c\n", str1[i]);
                else if (isspace(str1[i + 1]) != 0) 
                    printf("%c\n", str1[i]);
                else
                    printf("%c", str1[i]);
            }
        }
    }
    if (fclose(infile) == EOF)
        fprintf(stderr, "%s: could not fclose() the infile\n", argv[0]);
    return EXIT_FAILURE;
}

