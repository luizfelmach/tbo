#include <ctype.h>
#include <malloc.h>
#include <string.h>

#include "stack.h"

int is_operator(char c);
int eval(char op, int a, int b);
int char_to_number(char n);

int main(int argc, char* argv[]) {
    stack opns = stack_init(sizeof(int));
    stack oprs = stack_init(sizeof(char));
    int res;
    char exp[1024] = "( 100 * ( 5 * ( ( ( 9 + 28 ) * ( 43 * 1 ) ) + 7112 ) ) )";

    if (argc == 2) {
        strcpy(exp, argv[1]);
    }

    char* c = exp;
    while (*c) {
        if (*c == ' ') {
            c++;
            continue;
        }
        if (is_operator(*c)) {
            stack_push(oprs, c);
        } else if (*c == ')') {
            int a, b;
            char op;
            stack_pop(oprs, &op);
            stack_pop(opns, &a);
            stack_pop(opns, &b);
            int res = eval(op, a, b);
            stack_push(opns, &res);
        } else if (isdigit(*c) && !isdigit(*(c - 1))) {
            int val;
            sscanf(c, " %d ", &val);
            printf("%d\n", val);
            stack_push(opns, &val);
        }
        c++;
    }

    stack_pop(opns, &res);
    printf("%s = %d\n", exp, res);

    stack_destroy(opns);
    stack_destroy(oprs);
    return 0;
}

int is_operator(char c) {
    if (c == '*' || c == '/' || c == '+' || c == '-') return 1;
    return 0;
}

int eval(char op, int a, int b) {
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '+') return a + b;
    return a - b;
}

int char_to_number(char n) { return n - '0'; }
