#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

int main(int argc, char *argv[])
{
	int i, array[10];

	for (i = 0; i < 10; i++)
		array[i] = i+1;

	stack_t stack = stack_new();
	if (stack == NULL)
		exit(EXIT_FAILURE);
	
	for (i = 0; i < 10; i++)
		stack_push(stack, &array[i]);

	for (i = 0; i < 10; i++)
		printf("%d ", *(int *)stack_pop(stack));
	printf("\n");

	stack_free(&stack);

	return 0;
}
