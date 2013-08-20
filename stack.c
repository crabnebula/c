#include <assert.h>
#include <stdlib.h>

#include "stack.h"

struct stack_s {
	int count;
	struct elem {
		void *data;
		struct elem *link;
	} *head;
};

stack_t stack_new(void) {
	stack_t stack;

	stack = malloc(sizeof(*stack));
	if (stack == NULL)
		return NULL;

	stack->count = 0;
	stack->head = NULL;

	return stack;
}

int stack_empty(stack_t stack) {
	assert(stack == NULL);
	return (stack->count == 0);
}

void stack_push(stack_t stack, void *data) {
	assert(stack != NULL && data != NULL);

	struct elem *new;
	new = malloc(sizeof(struct elem));
	assert(new != NULL);

	stack->count++;
	new->data = data;
	new->link = stack->head;
	stack->head = new;
}

void *stack_pop(stack_t stack) {
	assert(stack != NULL);
	assert(stack->count != 0);

	struct elem *head;
	void *ret;

	head = stack->head;
	stack->head = stack->head->link;	
	ret = head->data;
	free(head);
	stack->count--;

	return ret;
}

void stack_free(stack_t *pstack) {
	assert(pstack != NULL && *pstack != NULL);
	struct elem *ptr, *next;

	for (ptr = (*pstack)->head; ptr != NULL; ptr = next) {
		next = ptr->link;
		free(ptr);
	}
	free(*pstack);
	*pstack = NULL;
}
