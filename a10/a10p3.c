/*
 * File:     a10p3.c
 * Author:   Lei Xie   100123800
 * Date:     2014/11/19
 * Version:  1.0
 *
 * Purpose:     The prpgram which read in a binary data, check the endian first
 *              and skip unused bytes print which endian the file is, the number
 *              of value data and the value of each data, one per line
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 4 

int
main(int argc, char * argv[])
{
    char buf[BUF_SIZE];
    FILE * in;
    int ret,endian,temp;
    int count = 0;
    /* Warnning if the arguments are not correct */
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <infile>\n", argv[0]);
        return EXIT_FAILURE;
    }
    /* open the fiel */
    in = fopen(argv[1], "rb");
    /* Warnning if the file can not be open */
    if (in == NULL)
    {
        fprintf(stderr, "Can not open %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    /* count the valued data and check which endian is the file */
    while (1)
    {
        ret = fread(buf, sizeof(int), 1, in);
        if (ret != 1)
            break;
        count++;
        if (buf[0] == 2 && count == 1)
        {
            endian = 2;
            printf("The file is little-endian\n");
            continue;
        }
        if (buf[0] == 1 && count == 1)
        {
            endian = 1;
            printf("The file is big-endian\n");
            continue;
        }
    }
    printf("It contains the folwing %d values:\n", (count - 1) * BUF_SIZE);
    rewind(in);
    count = 0;
    /* print the each value */
    while (1)
    {
        ret = fread(buf, sizeof(int), 1, in);
        if (ret != 1)
            break;
        count++;
        if (count == 1)
            continue;
        if (endian == 2)
        {
            /* reverse the data */
            temp = buf[0];
            buf[0] = buf[3];
            buf[3] = temp;
            temp = buf[1];
            buf[1] = buf[2];
            buf[2] = temp;
        }
        for (int i = 0; i < BUF_SIZE; i++)
        {
            printf("%d\n", buf[i]);
        }
    }
    ret = fclose(in);
    /* warnning if can not close the file */
    if (ret != 0)
        fprintf(stderr, "Can not close file: %s\n", argv[0]);

    return EXIT_SUCCESS;
}
