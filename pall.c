#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/


#define STACK_SIZE 100

typedef struct
{
int data[STACK_SIZE];
int top;
} Stack;

void pall(Stack *stack)
{
for (int i = stack->top; i >= 0; i--)
{
printf("%d\n", stack->data[i]);
}
}

int main()
{
Stack stack;
stack.top = -1;

// Simulate pushing some values onto the stack
push(&stack, 5);
push(&stack, 10);
push(&stack, 20);

// Execute the pall opcode
pall(&stack);

return (0);
}
