#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 128
#define DELIM "|"

int main(int argc, char* argv[])
{
    char str[LENGTH];
    char *name = NULL;
    char *final;
    printf("Please input your data: xxx|ddd: ");
    fgets(str, LENGTH, stdin);

#if DEBUG
    printf("%s\n", str);
#endif

    name = strtok(str, DELIM);
    final = strtok(NULL, DELIM);

    int finalgrade = atoi(final);
#if DEBUG
    printf("name: %s, final: %d.\n", name, finalgrade);
#endif

    return EXIT_SUCCESS;
}
