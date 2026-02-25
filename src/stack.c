#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int* data;
    size_t size;
    size_t capacity;
};
 
static bool stack_grow(Stack* s) {
    size_t new_cap = (s->capacity == 0) ? 4 : (s->capacity * 2);
    int* new_data = (int*)realloc(s->data, new_cap * sizeof(int));
    if (!new_data) return false;

    s->data = new_data;
    s->capacity = new_cap;
    return true;
}

Stack* stack_new(void) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (!s) return NULL;

    s->data = NULL;
    s->size = 0;
    s->capacity = 0;

    // optional: direkt initiale Kapazität reservieren
    if (!stack_grow(s)) {
        free(s);
        return NULL;
    }
    return s;
}

void stack_free(Stack* stack) {
    if (!stack) return;
    free(stack->data);
    free(stack);
}

size_t stack_length(const Stack* stack) {
    return stack ? stack->size : 0;
}

bool stack_is_empty(const Stack* stack) {
    return !stack || stack->size == 0;
}

bool stack_push(Stack* stack, int value) {
    if (!stack) return false;

    if (stack->size == stack->capacity) {
        if (!stack_grow(stack)) return false;
    }

    stack->data[stack->size] = value;
    stack->size++;
    return true;
}

bool stack_pop(Stack* stack, int* out_value) {
    if (!stack || stack->size == 0) return false;

    stack->size--;
    if (out_value) {
        *out_value = stack->data[stack->size];
    }
    return true;
}

bool stack_peek(const Stack* stack, int* out_value) {
    if (!stack || stack->size == 0) return false;

    if (out_value) {
        *out_value = stack->data[stack->size - 1];
    }
    return true;
}

void stack_print(const Stack* stack) {
    if (!stack) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (size_t i = 0; i < stack->size; i++) {
        printf("%d", stack->data[i]);
        if (i + 1 < stack->size) printf(", ");
    }
    printf("]\n");
}