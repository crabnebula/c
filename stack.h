#ifndef _STACK_H
#define _STACK_H

typedef struct stack_s *stack_t;

extern stack_t stack_new(void);
extern int stack_empty(stack_t stack);
extern void stack_push(stack_t stack, void *data);
extern void *stack_pop(stack_t stack);
extern void stack_free(stack_t *pstack);

#endif
