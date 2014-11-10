#include <stdio.h>
#include <stdlib.h>

char *
reverse_dup(char * s)
{
    char *ip = s;
    int i = - 1;
    char *s_rev;
    s_rev = malloc(sizeof(s));
    while (*ip)
    {
        ip++;
        i++;
    }
    while (i >= 0)
    {
        ip--;
        *s_rev++ = *ip;
        --i;
    }
    *s_rev = '\0';
    return s_rev;
}

int
main(int argc, char * argv[])
{
    char * s = "This is a string !";
    char * s_rev = reverse_dup(s);
    printf("|%s| reverses to |%s|\n", s, s_rev);
    return 0;
}
