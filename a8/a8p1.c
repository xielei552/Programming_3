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
    const char *p = str->string_data;
    while (*p++ != 0)
    {
        len++;
    }
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
    memcpy(dst->string_data, src->string_data, space_wanted);
    dst->string_length = space_wanted - 1;
    dst->allocated_block_length = dst->string_length - 1;
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

int
my_strcat(mystring_T dst, const mystring_T src)
{
    int space_wanted;
    int i,j;
    if (dst == NULL)
        return 1;
    if (src == NULL)
        return 2;
    space_wanted = strlen(dst->string_data) + strlen(src->string_data) + 1;
    if (space_wanted > dst->allocated_block_length)
    {
        char * new_block = malloc(space_wanted);
        if (new_block == NULL)
            return 3;
    }
    else if (space_wanted < dst->allocated_block_length / 2)
    {
        if (realloc(dst->string_data, 2 * space_wanted) == NULL)
        {
            return 4;
        }
        dst->allocated_block_length = 2 * space_wanted;
    }
    for (i = 0; dst->string_data[i] != '\0'; i++)
        ;
    for (j = 0; src->string_data[j] != '\0'; j++)
    {
        dst->string_data[i + j] = src->string_data[j];
    }
    dst->string_data[i + j] = '\0';
    return 0;
}

int
my_strcat_Cstr(mystring_T dst, const char * src)
{
    int space_wanted;
    int i,j;
    if (dst == NULL)
        return 1;
    if (src == NULL)
        return 2;
    space_wanted = strlen(dst->string_data) + strlen(src) + 1;
    if (space_wanted > dst->allocated_block_length)
    {
        char * new_block = malloc(space_wanted);
        if (new_block == NULL)
            return 3;
    }
    else if (space_wanted < dst->allocated_block_length / 2)
    {
        if (realloc(dst->string_data, 2 * space_wanted) == NULL)
        {
            return 4;
        }
        dst->allocated_block_length = 2 * space_wanted;
    }
    for (i = 0; dst->string_data[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++)
    {
        dst->string_data[i + j] = src[j];
    }
    dst->string_data[i + j] = '\0';
    return 0;
}


const char * my_str_Cstr(const mystring_T str)
{
    if (str == NULL)
        return NULL;
    else
        return str->string_data;
}

int
destroy_mystr(mystring_T * mystr_p)
{
    if (mystr_p == NULL)
        return 1;
    else
    {
        free((*mystr_p)->string_data);
        free(*mystr_p);
    }
    return 0;
}
int
main(int argc, char *argv[])
{
    printf("my_strlen(NULL) returns %ld\n\n", my_strlen(NULL));
    printf("my_strcpy_Cstr(NULL, NULL) returns %d\n\n",
            my_strcpy_Cstr(NULL,NULL));
    printf("my_strcpy(NULL, NULL) returns %d\n\n", my_strcpy(NULL,NULL));
    printf("my_strcat(NULL, NULL) returns %d\n\n", my_strcat(NULL,NULL));
    printf("my_strcat_Cstr(NULL, NULL) returns %d\n\n",
            my_strcat_Cstr(NULL,NULL));
    printf("my_str_Cstr(NULL) returns %s\n\n", my_str_Cstr(NULL));
    mystring_T test1 = new_mystr();
    mystring_T test2 = new_mystr();
    test2->string_data = "bbbb";
    printf("my_strcpy_Cstr(test1, 'aaa') return %d\n\n",
            my_strcpy_Cstr(test1, "aaa"));
    printf("my test1 is now '%s'\n\n", my_str_Cstr(test1));
    printf("my_strcpy(test1, test2) return %d\n\n", my_strcpy(test1, test2));
    printf("my test1 is now '%s'\n\n", my_str_Cstr(test1));
    printf("my_strlen(test2) return %ld\n\n", my_strlen(test2));
    printf("my test1 is now '%s'\n\n", my_str_Cstr(test1));
    printf("my test2 is now '%s'\n\n", my_str_Cstr(test2));
#ifdef DEBUG
    int ret;
    ret = destroy_mystr(&test1);
    if (ret == 1)
        printf("test1->string_data is NULL");
    if (ret == 0)
    printf("my test1 is now '%s'\n\n", my_str_Cstr(test1));
#endif
    printf("my_strcat(test1, test2) return %d\n\n", my_strcat(test1, test2));
    printf("my test1 is now '%s'\n\n", my_str_Cstr(test1));
    printf("my_strcat_Cstr(test1, 'cccc') return %d\n\n",
            my_strcat_Cstr(test1, "cccc"));
    printf("my test1 is now '%s'\n\n", my_str_Cstr(test1));
    return EXIT_SUCCESS;
}
