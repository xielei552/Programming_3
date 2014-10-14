/*
 * File:     a4p3.c
 * Author:   Lei Xie   100123800
 * Date:     2014/09/30
 * Version:  1.0
 *
 * Purpose:
 * rogram which opens two files,in and out. It copies 
 * the contents of in to out, except that it repalces:
 * 1. equences of two or more spaces and/or tabs in with one space;
 * 2. single tab characters with a single space;
 * 3. and the two-character sequence “BZ” with “Bravo Zulu”.
 */
#include <stdio.h>
#include <stdlib.h>

#define CHAR1 'B'
#define CHAR2 'Z'

int
main(int argc, char *argv[])
{
    FILE *fin, *fout;
    /* Invalid value for char (-5) */
    int c, pre_char = -5;
    fin = fopen(argv[1], "r");
    /* warning messages */
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s inputfile outputfile\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (fin == NULL)
    {
        fprintf(stderr, "File not exist!\n");
        return EXIT_FAILURE;
    }

    fout = fopen(argv[2], "w");
    /* continue until EOF */
    while ((c = fgetc(fin)) != EOF)
    {
        if (c == CHAR2)
        {
            /* using pre_char get both B and Z */
            if (pre_char == CHAR1)
            {
                fprintf(fout,"ravo Zulu");
                pre_char = 'u';
            }
            else
            {
                fputc(c, fout);
                pre_char = c;
            }
        }
        /* do nothing when many tabs and spaces */
        else if ((c == ' ' || c == '\t') && pre_char == ' ')
            ;
        /* deal with the space tab situation */
        else
        {
            if (c == '\t')
            {
                fputc(' ', fout);
                pre_char = ' ';
            }
            else
            {
                fputc(c, fout);
                pre_char = c;
            }
        }
    }
    fclose(fin);
    fclose(fout);
    return EXIT_SUCCESS;
}


