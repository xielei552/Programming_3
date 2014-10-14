/*
 * File:     a3p2.c
 * Author:   Lei Xie   100123800
 * Date:     2014/09/24
 * Version:  1.0
 *
 * Purpose:
 * rogram which takes an input file and reverses each 
 * of its lines, writing the output to another file.        
 */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 81

int
main(int argc, char* argv[])
{
    FILE *fin;
    FILE *fout;
    char in[ARRAY_SIZE];
    char out[ARRAY_SIZE];
    int counter = 0;
    int i, j;
    fin = fopen(argv[1], "r");

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s file file.rev\n", argv[0]);
        return EXIT_FAILURE;
    }
    /*if the file is empty error message exit*/
    if (fin == NULL)
    {
        perror("File not exist!\n");
        return EXIT_FAILURE;
    }

    char c;
    fout = fopen(argv[2], "w");
    
    /*a loop for transfer each char in to different position*/
    while (1)
    {
        c = getc(fin);
        if (c != EOF && c != '\n')
        {
            in[counter++] = c;
        }
        else
        {
            for (i = 0, j = counter - 1; j >= 0; i++, j--)
            {
                out[i] = in[j];
            }

            if (c == '\n')
            {
                out[counter] = '\n';
                out[counter+1] = '\0';
                fputs(out, fout);
                counter = 0;
                continue;
            }
            else
            {
                out[counter] = '\0';
                fputs(out, fout);
                break;
            }
        }
    }
    fclose(fin);
    fclose(fout);
    return EXIT_SUCCESS;
}


