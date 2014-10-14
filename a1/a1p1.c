/*
 * File:     a1p1.c
 * Author:   Lei Xie   100123800
 * Date:     2014/09/10
 * Version:  1.0
 *
 * Purpose:
 * Help the teacher to caculate the final grade
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LENGTH 128
#define DELIM "|"
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

int main(int argc, char* argv[])
{
    do
    {
        char str[LENGTH];
        char *name = NULL, *final = NULL, *mid = NULL, *bonus = NULL; 
        char *as1 = NULL, *as2 = NULL, *as3 = NULL, *as4 = NULL;
        char *as5 = NULL, *as6 = NULL, *cheat = NULL;

        /*get the string from the input*/
        fgets(str, LENGTH, stdin);

        name = strtok(str, DELIM);
        final = strtok(NULL, DELIM);
        mid = strtok(NULL, DELIM); 
        bonus = strtok(NULL, DELIM);
        cheat = strtok(NULL, DELIM);
        as1 = strtok(NULL, DELIM);
        as2 = strtok(NULL, DELIM);
        as3 = strtok(NULL, DELIM);
        as4 = strtok(NULL, DELIM);
        as5 = strtok(NULL, DELIM);
        as6 = strtok(NULL, DELIM);

        /*name the number i tok from the string*/
        double fg = atof(final);
        double mg = atof(mid);
        double bg = atof(bonus);
        double courseg = atof(cheat);
        double as1g = atof(as1);
        double as2g = atof(as2);
        double as3g = atof(as3);
        double as4g = atof(as4);
        double as5g = atof(as5);
        double as6g = atof(as6);
    
        double f,as,sum;
        char *cg = NULL;
        
        /*the assignment grade count in the final grade*/
        sum = as1g + as2g + as3g + as4g + as5g + as6g;
        as = MIN(100, 100 * (sum) / ((20 + 60 * 5) - 60)); 

        /*if got caught chaeting get 0 and F in final grade*/
        if(courseg > 0)
        {
            f = 0;
            cg = "F";
        }
        else
        {
            f = 0.5 * fg + 0.1 * mg + bg + 0.1 * as;
            if(fg < 40)
            {
                f += 0.3 * fg;
            }
            else
            {
                if(fg > 50)
                {
                    f += 0.2 * MAX(fg,mg);
                    f += 0.1 * MAX(fg,as);
                }
                else
                {
                    f +=0.02 * ((fg - 40) * MAX(fg,mg) + (50 - fg) * fg);
                    f +=0.01 * ((fg - 40) * MAX(fg,as) + (50 - fg) * fg);
                }
            }

            if(mg < 40)
            {
                f = MIN(f, mg);
            }
            if(as < 50)
            {
                f = MIN(f,as);
            }
        }
        /*double to int*/
        f = (int)(f + 0.5);

        /*numeric grade*/
        if(f < 50)
        {
            cg = "F";
        }
        if(50 <= f && f <= 52)
        {
            cg = "D-";
        }
        if(53 <= f && f <= 56)
        {
            cg = "D";
        }
        if(57 <= f && f <= 59)
        {
            cg = "D+";
        }
        if(60 <= f && f <= 62)
        {
            cg = "C-";
        }
        if(63 <= f && f <= 66)
        {
            cg = "C";
        }
        if(67 <= f && f <= 69)
        {
            cg = "C+";
        }
        if(70 <= f && f <= 72)
        {
            cg = "B-";
        }
        if(73 <= f && f <= 76)
        {
            cg = "B";
        }
        if(77 <= f && f <= 79)
        {
            cg = "B+";
        }
        if(80 <= f && f <= 86)
        {
            cg = "A-";
        }
        if(87 <= f && f <= 93)
        {
            cg = "A";
        }
        if(94 <= f)
        {
            cg = "A+";
        }
        printf("%-29s %-2s %3d\n", name, cg, (int)f);
    } while(1);
    return EXIT_SUCCESS;
}
