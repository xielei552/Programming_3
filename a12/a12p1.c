/*
 * File:     a12p1.c
 * Author:   Lei Xie   100123800
 * Date:     2014/12/1
 * Version:  1.0
 *
 * Purpose:     The prpgram which read commend-line argumnet if it is an
 *              integer call enter_another_number() function
 *              if it is 'e' call how_many_evens()
 *              if it is 'o' call how_many_odds()
 *              if it is 'r' call reset_counters()
 */
#include <stdio.h>
#include <stdlib.h>
#include "count_num.h"

int
main(int argc, char * argv[])
{
    int ret, ret2;
    int c;
    char a,b;
    int even, odd;
    for (int i = 1; i < argc; i++)
    {
        ret = sscanf(argv[i], "%d%c", &c, &a);
        if (ret != 1)
        {
            /* warnning if a letter follow by integer */
            if (ret == 2)
            {
                fprintf(stderr, "invalued input: %s (integer or one char)\n"
                        , argv[i]);
                return EXIT_FAILURE;
            }
            else
            {
                ret2 = sscanf(argv[i], "%c%c", &a, &b);
                /* warnnning if a letter follow by a letter */
                if (ret2 != 1)
                {
                    fprintf(stderr, "invalued input: %s (int or one char)\n"
                            , argv[i]);
                    return EXIT_FAILURE;
                }
                else
                {
                    switch(a)
                    {
                        case 'e':
                            even = how_many_evens();
                            if (even == 1)
                                printf("%d even number has been entered\
 so far.\n"
                                    , how_many_evens());
                            else
                                printf("%d even numbers has been entered\
 so far.\n"
                                    , how_many_evens());
                            break;
                        case 'o':
                            odd = how_many_odds();
                            if (odd == 1)
                                printf("%d odd number has been entered\
 so far.\n"
                                    , how_many_odds());
                            else
                                printf("%d odd numbers has been entered\
 so far.\n"
                                    , how_many_odds());
                            break;
                        case 'r':
                            reset_counters();
                            break;
                        default:
                            fprintf(stderr, "the letter /%s/ should be in\
 {'e','o','r'}\n", argv[i]);
                    }
                }

            }
        }
        /* if the arguement is an integer */
        else
        {
            enter_another_number(c);
        }
    }
    return EXIT_SUCCESS;
}
