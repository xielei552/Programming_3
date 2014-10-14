#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
typedef int IntArr_T[MAX];
typedef struct
{
    IntArr_T integers;
    int count;
} Integers_T;

Integers_T
onlyEvens(Integers_T old)
{
    Integers_T new;
    new.count = 0;

    for (int i = 0; i < old.count; i++)
    {
        if (old.integers[i] % 2 == 0)
        {
            new.count++;
            new.integers[i] = old.integers[i];
        }
    }
    return new;
}

int
main(int argc, char *argv[])
{
    Integers_T test, afterTest;
    test.count = 10;
    test.integers[test.count] = {{0, 3, 3, 1, 41, 2, 5, 1, 6, 1, 62}};

    afterTest = onlyEvens(test);

    return EXIT_SUCCESS;
}
