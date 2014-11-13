/*
 * File:     a8p1.c
 * Author:   Lei Xie   100123800
 * Date:     2014/11/10
 * Version:  1.0
 *
 * Purpose:     the program which have a pointer struct, and a struct type
 *              function new_str() which create a struct and its memory block
 *              my_strlen() which return the length of the string in the struct
 *              my_strcpy() which copy a string in src struct to the string in
 *              dst struct
 *              my_strcpy_Cstr() which copy a string to the string in dst struct
 *              my_strcat() which append a string in src struct to a string in 
 *              dst struct
 *              my_strcat_Cstr() which append a string to a string in dst 
 *              struct
 *              mu_str_Cstr() print out the string in the struct
 *              destroy_mystr() free the memory used in the struct
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char * string_data;
    long string_length;
    long allocated_block_length;
}*mystring_T;

/*
 * Name:        new_mystr()
 * purpose:     it is a function which create a struct and its memery block 
 * Output:      none
 * Returns:     return NULL means can not new the struct return new means 
 *              return the new struct with allocated memory
 * Assumptions: none
 * Bugs:        none
 * Notes:       allocated_block_length should less than string_length
 */
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

/*
 * Name:        my_strlen
 * purpose:     it is a function which return the length of the string in the
 *              struct  
 * Output:      none
 * Returns:     return 1 means the string is empty return len means return the
 *              string_length
 * Assumptions: none
 * Bugs:        none
 * Notes:       use a const pointer to count the length of the string
 */
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
/*
 * Name:        my_strcpy
 * purpose:     my_strcpy() which copy a string in src struct to the string in
 *              dst struct
 * Output:      none
 * Returns:     retrun 1 means the struct dst is NULL
 *              return 2 means the struct src is NULL
 *              return 3 means after malloc() the new struct is NULL
 *              return 4 means after remalloc() the double space of struct
 *              the struct is NULL
 *              return 0 means the function of copy is success
 * Assumptions: none
 * Bugs:        none
 * Notes:       many memory check to ensure the memory is enough for store
 *              the struct
 */
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

/*
 * Name:        my_strcpy_Cstr
 * purpose:     my_strcpy_Cstr() which copy a string to the string in dst struct
 * Output:      none
 * Returns:     retrun 1 means the struct dst is NULL
 *              return 2 means the src is NULL
 *              return 3 means after malloc() the new struct is NULL
 *              return 4 means after remalloc() the double space of struct
 *              the struct is NULL
 *              return 0 means the function of copy is success
 * Assumptions: none
 * Bugs:        none
 * Notes:       many memory checks to ensure the memory is enough to store
 *              the struct
 */
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

/*
 * Name:        my_strcat
 * purpose:     my_strcat() which append a string in src struct to a string in 
 *              dst struct
 * Output:      none
 * Returns:     retrun 1 means the struct dst is NULL
 *              return 2 means the struct src is NULL
 *              return 3 means after malloc() the new struct is NULL
 *              return 4 means after remalloc() the double space of struct
 *              the struct is NULL
 *              return 0 means the function of copy is success
 * Assumptions: none
 * Bugs:        none
 * Notes:       many memory checks to ensure the memory is enough to store
 *              the struct
 */
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
/*
 * Name:        my_strcat_Cstr
 * purpose:     my_strcat_Cstr() which append a string to a string in dst 
 *              struct
 * Output:      none
 * Returns:     retrun 1 means the struct dst is NULL
 *              return 2 means the struct src is NULL
 *              return 3 means after malloc() the new struct is NULL
 *              return 4 means after remalloc() the double space of struct
 *              the struct is NULL
 *              return 0 means the function of copy is success
 * Assumptions: none
 * Bugs:        none
 * Notes:       many memory checks to ensure the memory is enough to store
 *              the struct
 */
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

/*
 * Name:        func_compare
 * purpose:     mu_str_Cstr() print out the string in the struct 
 * Output:      none
 * Returns:     return NULL means the string is empty return str->string_data
 *              means return the out put string
 * Assumptions: none
 * Bugs:        none
 */
const char * my_str_Cstr(const mystring_T str)
{
    if (str == NULL)
        return NULL;
    else
        return str->string_data;
}
/*
 * Name:        destroy_mystr
 * purpose:     destroy_mystr() free the memory used in the struct 
 * Output:      none
 * Returns:     return 0 means the memory is successfully destroyed
 *              return 1 means the struct is empty
 * Assumptions: none
 * Bugs:        none
 * Notes:       free the string first then free the struct
 */
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
    /* the first test */
    printf("my_strlen(NULL) returns %ld\n\n", my_strlen(NULL));
    printf("my_strcpy_Cstr(NULL, NULL) returns %d\n\n",
            my_strcpy_Cstr(NULL,NULL));
    printf("my_strcpy(NULL, NULL) returns %d\n\n", my_strcpy(NULL,NULL));
    printf("my_strcat(NULL, NULL) returns %d\n\n", my_strcat(NULL,NULL));
    printf("my_strcat_Cstr(NULL, NULL) returns %d\n\n",
            my_strcat_Cstr(NULL,NULL));
    printf("my_str_Cstr(NULL) returns %s\n\n", my_str_Cstr(NULL));

    /* new the structand allocated memory */
    mystring_T test1 = new_mystr();
    mystring_T test2 = new_mystr();

    /* the second test */
    printf("my_strcpy(test1, NULL) return %d\n\n", my_strcpy(test1, NULL));
    printf("my_strcpy(NULL, test2) return %d\n\n", my_strcpy(NULL, test2));
    printf("my_strcpy_Cstr(test1, NULL) return %d\n\n", my_strcpy_Cstr(test1, NULL));
    printf("my_strcpy_Cstr(NULL, 'aaa') return %d\n\n", my_strcpy_Cstr(NULL, "aaa"));
    printf("my_strcat(test1, NULL) return %d\n\n", my_strcat(test1, NULL));
    printf("my_strcat(NULL, test2) return %d\n\n", my_strcat(NULL, test2));
    printf("my_strcat_Cstr(test1, NULL) return %d\n\n", my_strcat_Cstr(test1, NULL));
    printf("my_strcat_Cstr(NULL, 'aaa') return %d\n\n", my_strcat_Cstr(NULL, "aaa"));

    /* the third test */
    printf("my_strcpy_Cstr(test1, 'aaa') return %d\n\n",
            my_strcpy_Cstr(test1, "aaa"));
    printf("my_strcpy_Cstr(test2 'bbbb') return %d\n\n",
            my_strcpy_Cstr(test2, "bbbb"));
    printf("my test1 is now '%s'\n\n", my_str_Cstr(test1));
    printf("my_strcpy(test1, test2) return %d\n\n", my_strcpy(test1, test2));
    printf("my test1 is now '%s'\n\n", my_str_Cstr(test1));
    printf("my_strlen(test2) return %ld\n\n", my_strlen(test2));
    printf("my test1 is now '%s'\n\n", my_str_Cstr(test1));
    printf("my test2 is now '%s'\n\n", my_str_Cstr(test2));

    /* bonus addition #1 */
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
