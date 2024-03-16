#ifndef STACK_H

typedef struct Stack *stack;

stack stack_init(int size);
void stack_push(stack, void *);
void stack_pop(stack, void *);
int stack_empty(stack);
void stack_destroy(stack);

#endif  // !STACK_H
