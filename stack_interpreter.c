#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct
{
int data[MAX_STACK_SIZE];
int top;
} Stack;

void initStack(Stack *stack)
{
stack->top = -1;
}

int isFull(Stack *stack) 
{
return stack->top == MAX_STACK_SIZE - 1;
}

int isEmpty(Stack *stack)
{
return stack->top == -1;
}

void push(Stack *stack, int value)
{
if (isFull(stack))
{
fprintf(stderr, "Stack is full. Cannot push.\n");
exit(EXIT_FAILURE);
}
stack->data[++stack->top] = value;
}

int pop(Stack *stack)
{
if (isEmpty(stack))
{
fprintf(stderr, "Stack is empty. Cannot pop.\n");
exit(EXIT_FAILURE);
}
return stack->data[stack->top--];
}

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
initStack(&stack);

FILE *file = fopen("input.txt", "r");
if (file == NULL)
{
fprintf(stderr, "Error opening file.\n");
return EXIT_FAILURE;
}

char line[100];
int line_number = 0;
while (fgets(line, sizeof(line), file))
{
line_number++;
char opcode[10];
int value;

if (sscanf(line, "%s %d", opcode, &value) == 2)
{
if (strcmp(opcode, "push") == 0)
{
push(&stack, value);
} else {
fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
return EXIT_FAILURE;
}
} else if (strcmp(opcode, "pall") == 0)
{
pall(&stack);
} else
{
fprintf(stderr, "L%d: Invalid syntax\n", line_number);
return EXIT_FAILURE;
}
}

fclose(file);
return EXIT_SUCCESS;
}
