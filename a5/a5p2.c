/*
 * File:     a5p2.c
 * Author:   Lei Xie   100123800
 * Date:     2014/10/05
 * Version:  1.0
 *
 * Purpose:
 * this program could be used to help people who do not know French
 * in various conversational situations using random(), srandom(),
 * time() functions to random output freanch sectence
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SENTENCE 6
int
main(int argc, char *argv[])
{
    int a;
    srandom(time(NULL));
    /* get the random number mod short_number mod num_sentence */ 
    a = random() % NUM_SENTENCE;
    switch (a)
    {
        case 0:
            printf("C’est dommage, mais je ne parle pas francais.\n");
            break;
        case 1:
            printf("Je regrette que je ne parle pas francais.\n");
            break;
        case 2:
            printf("Je m’excuse, mais je ne parle pas francais.\n");
            break;
        case 3:
            printf("C’est triste, mais je ne parle pas francais.\n");
            break;
        case 4:
            printf("Je suis desolee, mais je ne parle pas francais.\n");
            break;
        case 5:
            printf("C’est tragique, mais je ne parle pas francais.\n");
            break;
    }
    return EXIT_SUCCESS;
}
