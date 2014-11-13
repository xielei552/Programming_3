/*
 * File:    my_stack.c
 * Author:  Lei Xie
 * Date:    November 12, 2014
 * Version: 1.0
 *
 * Description: This file describes the interface to a number of functions.
 */

#include "my_stack.h"
#include <stdio.h>
#include <stdlib.h>

struct list_element
{
    int field1;
    struct list_element * next;
};

/*
 * Name:        new_stack
 * purpose:     it is a function which allocaked memory for the struct 
 *              * stack_t
 * Output:      none
 * Returns:     return new means return the new struct with alocated memory
 *              return the return NULL means can not allocated memory for the
 *              struct
 * Assumptions: none
 * Bugs:        none
 */
stack_t
new_stack()
{
    stack_t new = malloc(sizeof(stack_t));
    if (new == NULL)
        return NULL;
    return new;
}

/*
 * Name:        push_stack
 * purpose:     it is a function which push a integer into top of linked list
 * Output:      none
 * Returns:     return 1 means the linked list is NULL
 *              return 2 means the can not new a list of element
 *              return 0 means success push an element in to the list
 * Assumptions: none
 * Bugs:        none
 */
int
push_stack(stack_t s, int data)
{
    if (s == NULL)
        return 1;
    stack_t node = new_stack();
    if (node == NULL)
        return 2;
    node->field1 = data;
    if (s->next == NULL)
        node->next = NULL;
    else
        node->next = s->next;
    s->next = node;
    return 0;
}

/*
 * Name:        pop_stack
 * purpose:     it is a function which pop out a integer from a linked list
 * Output:      none
 * Returns:     return 1 means the linked list is NULL
 *              return 0 means success pop out an element from the list
 * Assumptions: none
 * Bugs:        none
 */
int
pop_stack(stack_t s, int * data)
{
    if (s == NULL)
        return 1;
    stack_t top = s->next;
    *data = top->field1;
    s->next = top->next;
    free(top);
    return 0;
}

/*
 * Name:        top_stack
 * purpose:     it is a function which can find the top element in the stack
 * Output:      none
 * Returns:     return 1 means the stack is empty
 *              return 2 means reach to the end of stack
 *              return 0 means success to find the top of the element
 * Assumptions: none
 * Bugs:        none
 */
int
top_stack(const stack_t s, int * data)
{
    if (s == NULL)
        return 1;
    if (s->next == NULL)
        return 2;
    *data = s->next->field1;
    return 0;
}

/*
 * Name:        is_empty_stack
 * purpose:     it is a function which to check if the stack is empty
 * Output:      none
 * Returns:     return 1 means the stack is not NULL
 *              return 2 means the stack is not empty
 *              retrun 0 means the stack is empty
 * Assumptions: none
 * Bugs:        none
 */
int
is_empty_stack(const stack_t s)
{
    if (s == NULL)
        return 1;
    if (s->next == NULL)
        return 0;
    else
        return 2;
}

/*
 * Name:        destory_stack
 * purpose:     it is a function which destory the stack and the allocated
 *              memory
 * Output:      none
 * Returns:     return 1 means the stack is NULL
 *              return 0 success to destory the stack
 * Assumptions: none
 * Bugs:        none
 */
int
destroy_stack(stack_t * s_p)
{
    if (*s_p == NULL)
        return 1;
    free((*s_p)->next);
    free(*s_p);
    *s_p = NULL;
    return 0;
} 
