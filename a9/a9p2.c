#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"

int
main(int argc, char * argv[])
{
    stack_t stack1;
    int data;
    int ret;

    /* test the new_stack function */
    stack1 = new_stack();
    if (stack1 == NULL)
    {
        fprintf(stderr, "Failure to initialize a new stack\n");
        return EXIT_FAILURE;
    }
    printf("Success creaking stack\n");

    /* test the push_stack function */
    if (push_stack(stack1, 2) != 0)
    {
        fprintf(stderr, "Failure to push_stack()\n");
        return EXIT_FAILURE;
    }
    printf("Success push on to stack\n");
    if (push_stack(stack1, 3) != 0)
    {
        fprintf(stderr, "Failure to push_stack()\n");
        return EXIT_FAILURE;
    }
    printf("Success push on to stack\n");
    if (push_stack(stack1, 4) != 0)
    {
        fprintf(stderr, "Failure to push_stack()\n");
        return EXIT_FAILURE;
    }
    printf("Success push on to stack\n");

    /* test the pop_stack function */
    if (pop_stack(stack1, &data) != 0)
    {
        fprintf(stderr, "Failure to pop out data\n");
        return EXIT_FAILURE;
    }
    if (data != 4)
    {
        fprintf(stderr, "pop out worng data\n");
        return EXIT_FAILURE;
    }
    printf("Success poping correct value form stack\n");

    /* test the is_empty_stack function */
    ret = is_empty_stack(stack1);
    if (ret == 1)
    {
        fprintf(stderr, "Failure to check if the stack is empty\n");
        return EXIT_FAILURE;
    }
    if (ret == 0)
        printf("the stack1 is empty\n");
    else
        printf("the stack1 is not empty\n");

    /* test the top_stack function */
    ret = top_stack(stack1, &data);
    if (ret != 0)
        fprintf(stderr, "Failure to find the top of element\n");
    if (data != 3)
    {
        fprintf(stderr, "top out worng data\n");
        return EXIT_FAILURE;
    }
    printf("Success to find the correct top of element\n");

    /* test the destory_stack function */
    if (destroy_stack(&stack1) != 0)
    {
        fprintf(stderr, "Failure to destroy the stack\n");
        return EXIT_FAILURE;
    }
    printf("Success to destroy the stack!\n");

    return EXIT_SUCCESS;
}
