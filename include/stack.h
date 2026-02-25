#ifndef STACK_H
#define STACK_H

#include <stddef.h>  // size_t
#include <stdbool.h> // bool

typedef struct Stack Stack;

Stack* stack_new(void);
void stack_free(Stack* stack);

size_t stack_length(const Stack* stack);
bool stack_is_empty(const Stack* stack);


bool stack_push(Stack* stack, int value);


bool stack_pop(Stack* stack, int* out_value);
bool stack_peek(const Stack* stack, int* out_value);

void stack_print(const Stack* stack);

#endif 