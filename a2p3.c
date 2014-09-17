/*
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char menu;
    int invalid,valid;
    int n,back;

    invalid = 0;
    valid = 0;
    n = 0;

    while (1)
    {
        if(back == 1)
        {
            menu = n;
        }
        else
        {
            printf("What would you like to do (h for help)? ");
            scanf(" %c", &menu);
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
                system("date +%A");
                printf("\n");
                n = menu;
                back = 0;
                break;
            case '.':
                back = 1;
                break;

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
