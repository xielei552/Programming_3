#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char * string_data;
    long string_length;
    long allocated_block_length;
}*mystring_T;

mystring_T
new_mystr()
{
    mystring_T new;
    new = malloc(sizeof(*new));
    if (new == NULL)
        return NULL;
    new->string_data = NULL;
    new->string_length = -1;
    new->allocated_block_length = 0;

    return new;
}

long
my_strlen(const mystring_T str)
{
    if (str == NULL)
        return 1;
    long len = 0;
    while (str->string_data++)
        len++;
    return len;
}
int
my_strcpy(mystring_T dst, const mystring_T src)
{
    int space_wanted;
    if (dst == NULL)
        return 1;
    if (src == NULL)
        return 2;
    space_wanted =strlen(src->string_data) + 1;
    if (space_wanted > dst->allocated_block_length)
    {
        char * new_block = malloc(space_wanted);
        if (new_block == NULL)
            return 3;
        free(dst->string_data);
        dst->string_data = new_block;
        dst->allocated_block_length = space_wanted;
    }
    else if (space_wanted < dst->allocated_block_length / 2)
    {
        if (realloc(dst->string_data, 2 * space_wanted) == NULL)
        {
            return 4;
        }
        dst->allocated_block_length = 2 * space_wanted;
    }
    memcpy(dst->string_data, src, space_wanted);
    dst->string_length = space_wanted - 1;
    return 0;
}

int
my_strcpy_Cstr(mystring_T dst, const char * src)
{
    int space_wanted;
    if (dst == NULL)
        return 1;
    if (src == NULL)
        return 2;
    space_wanted =strlen(src) + 1;
    if (space_wanted > dst->allocated_block_length)
    {
        char * new_block = malloc(space_wanted);
        if (new_block == NULL)
            return 3;
        free(dst->string_data);
        dst->string_data = new_block;
        dst->allocated_block_length = space_wanted;
    }
    else if (space_wanted < dst->allocated_block_length / 2)
    {
        if (realloc(dst->string_data, 2 * space_wanted) == NULL)
        {
            return 4;
        }
        dst->allocated_block_length = 2 * space_wanted;
    }
    memcpy(dst->string_data, src, space_wanted);
    dst->string_length = space_wanted - 1;
    dst->allocated_block_length = dst->string_length - 1;
    return 0;
}

int my_strcat(mystring_T dst, const mystring_T src)
{
    if (dst == NULL)
        return 1;
    if (src == NULL)
        return 2;
    while (dst->string_data)
    {
        dst->string_data++;
    }
    while (dst->string_data++ == src->string_data++)
    {
        NULL;
    }
    return 0;
}
int
main(int argc, char *argv[])
{
    mystring_T test1 = new_mystr();
    mystring_T test2 = new_mystr();
    test1->string_data = "aaa";
    test1->string_length = 3;
    test1->allocated_block_length = 4;
    test2->string_data = "bb";
    test2->string_length = 2;
    test2->allocated_block_length = 3;
    printf("my return %d\n\n", my_strcpy_Cstr(test1,test2->string_data));
    printf("my_strcpy_Cstr(NULL, NULL) returns %d\n\n", my_strcpy_Cstr(NULL,NULL));
    printf("my_strcpy(NULL, NULL) returns %d\n\n", my_strcpy(NULL,NULL));
    printf("my_strccat(NULL, NULL) returns %d\n\n", my_strcat(NULL,NULL));
    return EXIT_FAILURE;
}
