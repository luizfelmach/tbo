#include "stack.h"

#include <stdlib.h>
#include <string.h>

struct Stack {
    char *data;
    int last, m_size, total;
};

stack stack_init(int size) {
    stack s = (stack)malloc(sizeof(struct Stack));
    s->last = 0;
    s->total = 1000;
    s->m_size = size;
    s->data = (char *)malloc(s->m_size * s->total);
    return s;
}
void stack_push(stack s, void *item) {
    if (s->last == s->total) {
        s->total *= 2;
        s->data = realloc(s->data, s->m_size * s->total);
    }
    memcpy(s->data + s->last * s->m_size, item, s->m_size);
    s->last += 1;
}

void stack_pop(stack s, void *ptr) {
    s->last -= 1;
    memcpy(ptr, s->data + s->last * s->m_size, s->m_size);
}

int stack_empty(stack s) { return s->last == 0; }

void stack_destroy(stack s) {
    free(s->data);
    free(s);
}
