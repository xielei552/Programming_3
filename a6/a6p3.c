#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    FILE * fin;
    char buf[20];
    fopen(argv[1], "r");
    fread(buf, 65, 1, fin);
    rewind(fin);
}
