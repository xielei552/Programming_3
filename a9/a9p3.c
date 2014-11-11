#include <stdio.h>
#include <stdlib.h>

char *
reverse_dup(char * s)
{
    if (s == NULL)
        return NULL;
    int i = 0;
    int len;
    char *s_rev;
    s_rev = malloc(sizeof(*s));
    while (*s)
    {
        s++;
        i++;
        len = i;
    }
    while (i > 0)
    {
        s--;
        *s_rev = *s;
        s_rev++;
        --i;
    }
    s_rev = s_rev - len;
    return s_rev;
}

int
main(int argc, char * argv[])
{
    char * s = "This is a string !";
    char * s_rev = reverse_dup(s);
    printf("|%s| reverses to |%s|\n", s, s_rev);
    char * s1 = NULL;
    char * s1_rev = reverse_dup(s1);
    printf("|%s| reverses to |%s|\n", s1, s1_rev);
    char * s2 = " ";
    char * s2_rev = reverse_dup(s2);
    printf("|%s| reverses to |%s|\n", s2, s2_rev);
    char * s3 = " aaaaaaaabbbbcdefghijklmnopqrse=tuvwxqqqqqqqqqqqqqqqqqqqq\
qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq\
qqqqqqqqqqqqqqqqqzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
wyz";
    char * s3_rev = reverse_dup(s3);
    printf("|%s| reverses to |%s|\n", s3, s3_rev);
    return EXIT_SUCCESS;
}
