/*
 * File:     a2p3.c
 * Author:   Lei Xie   100123800
 * Date:     2014/09/17
 * Version:  1.0
 *
 * Purpose:
 *      this program can mplement a simple text-based menu system. It will
 *      prompt the user for a choice, read in the choice, 
 *      confirm that the choice is valid, and then if valid execute 
 *      an action .
 *      IMOPRTANT: if the command was longer than 1 char, the program will
 *      ignore the rest of them just do the first command, and if you did not
 *      input anything or input space, the program will exit.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char menu;
    char str[50];
    int invalid,valid;
    int n,back,ninput;
    
    /*
     * invalid count invalid number of in put
     * valid cout valid number of input
     */
    invalid = 0;
    valid = 0;
    n = 0;

    while (1)
    {
        /*this if is design for command '.'*/
        if(back == 1)
        {
            menu = n;
        }
        else
        {
            /*input command and do the first command throw out others
             * if input space or nothing than exit
             */
            printf("What would you like to do (h for help)? ");
            fgets(str, 50, stdin);
            ninput = sscanf (str, " %c", &menu);
            if (ninput != 1)
            {
                fprintf(stderr, "No command captured, EXIT! \n");
                return EXIT_FAILURE;
            }
        }
        switch (menu)
        {
            case 'b':
                valid++;
                printf("%d\n", valid);
                printf("\n");
                n = menu;
                back = 0;
                break;
            case 'c':
                valid++;
                printf("%d\n", invalid);
                printf("\n");
                n = menu;
                back = 0;
                break;
            case 'd':
                valid++;
                system ("df");
                printf("\n");
                n = menu;
                back = 0;
                break;
            case 'f':
                valid++;
                system ("free");
                printf("\n");
                n = menu;
                back = 0;
                break;
            case 'h':
                /*
                 * the help function looks mess,due to the word limit of words
                 */
                valid++;
                printf("The following commands are implemented:\n");
                printf("b - print out how any invalid commands have");
                printf(" been entered\n");
                printf("c - print out how many valid commeands have ");
                printf("been entered\n");
                printf("d - run the %cdf%c command\n", '"', '"');
                printf("f - run the %cfree%c command\n", '"', '"');
                printf("h - get this help\n");
                printf("i - run the %cifconfig%c command\n", '"', '"');
                printf("l - run  the %cls%c command with no ", '"', '"');
                printf("options\n");
                printf("p - run the %cps%c command with the ", '"', '"');
                printf("%c-u%c option\n", '"','"' );
                printf("q - quit\n");
                printf("w - print the weekday\n");
                printf(". - repeat the last command\n\n");
                n = menu;
                back = 0;
                break;
            case 'i':
                valid++;
                system ("ifconfig");
                printf("\n");
                n = menu;
                back = 0;
                break;
            case 'l':
                valid++;
                system("ls");
                printf("\n");
                n = menu;
                back = 0;
                break;
            case 'p':
                valid++;
                system("ps -u");
                printf("\n");
                n = menu;
                back = 0;
                break;
            case 'q':
                printf("Good-bye.\n");
                return EXIT_SUCCESS; 
            case 'w':
                valid++;
                printf("The current weekday is ");

                printf("\n");
                n = menu;
                back = 0;
                break;
            case '.':
                /*back is the intger to find out what is the last command
                 */
                back = 1;
                break;
                /*give the warring sign for invalid input*/
            default:
                fprintf(stderr,"'%c' is an invalid command, please ", menu);
                fprintf(stderr,"try again.\n");
                invalid++;
                n = menu;
                back = 0;
                printf("\n");
                break;
        }
    }
    return EXIT_SUCCESS;
}
