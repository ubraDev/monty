#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
#define STACK_SIZE 100

typedef struct
{
int data[STACK_SIZE];
int top;
} Stack;

void initialize(Stack *stack)
{
stack->top = -1;
}

void push(Stack *stack, int value)
{
if (stack->top == STACK_SIZE - 1)
{
fprintf(stderr, "Stack overflow\n");
exit(EXIT_FAILURE);
}
stack->top++;
stack->data[stack->top] = value;
}

int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "Usage: %s <integer>\n", argv[0]);
return EXIT_FAILURE;
}

Stack stack;
initialize(&stack);

int value = atoi(argv[1]);
push(&stack, value);

return 0;
}
