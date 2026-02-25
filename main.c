#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "list.h"

/* ---------- Test-Helpers ---------- */
static void expect_int(const char* name, int got, int expected) {
    if (got == expected) printf("[OK]   %s = %d\n", name, got);
    else printf("[FAIL] %s: got %d, expected %d\n", name, got, expected);
}

static void expect_size(const char* name, size_t got, size_t expected) {
    if (got == expected) printf("[OK]   %s = %zu\n", name, got);
    else printf("[FAIL] %s: got %zu, expected %zu\n", name, got, expected);
}

static void expect_bool(const char* name, bool got, bool expected) {
    if (got == expected) printf("[OK]   %s\n", name);
    else printf("[FAIL] %s\n", name);
}

/* ---------- Tests ---------- */
static void run_tests(void) {
    printf("\n====================\n");
    printf("RUNNING TESTS\n");
    printf("====================\n");

    Stack* s = stack_new();
    expect_bool("stack_new() != NULL", s != NULL, true);
    if (!s) return;

    // empty checks
    expect_size("length(empty)", stack_length(s), 0);
    expect_bool("is_empty(empty)", stack_is_empty(s), true);

    int x = 0;
    expect_bool("peek(empty) == false", stack_peek(s, &x), false);
    expect_bool("pop(empty) == false", stack_pop(s, &x), false);

    // pushes
    expect_bool("push 10", stack_push(s, 10), true);
    expect_bool("push 20", stack_push(s, 20), true);
    expect_bool("push 30", stack_push(s, 30), true);

    expect_size("length(after pushes)", stack_length(s), 3);
    expect_bool("is_empty(after pushes) == false", stack_is_empty(s), false);

    // peek/top
    expect_bool("peek == true", stack_peek(s, &x), true);
    expect_int("peek value", x, 30);

    // pop LIFO
    expect_bool("pop #1", stack_pop(s, &x), true);
    expect_int("pop #1 value", x, 30);

    expect_bool("pop #2", stack_pop(s, &x), true);
    expect_int("pop #2 value", x, 20);

    expect_size("length(after 2 pops)", stack_length(s), 1);

    expect_bool("pop #3", stack_pop(s, &x), true);
    expect_int("pop #3 value", x, 10);

    expect_size("length(empty again)", stack_length(s), 0);
    expect_bool("is_empty(empty again)", stack_is_empty(s), true);

    // empty again
    expect_bool("pop(empty again) == false", stack_pop(s, &x), false);

    stack_free(s);

    printf("====================\n");
    printf("TESTS DONE\n");
    printf("====================\n\n");


        // --------------------
    // Queue Tests (FIFO)
    // --------------------
    Queue* q = queue_new();
    expect_bool("queue_new() != NULL", q != NULL, true);
    if (!q) {
        stack_free(s);
        return;
    }

    expect_size("queue_length(empty)", queue_length(q), 0);
    expect_bool("queue_is_empty(empty)", queue_is_empty(q), true);

    int y = 0;
    expect_bool("queue_peek(empty) == false", queue_peek(q, &y), false);
    expect_bool("queue_dequeue(empty) == false", queue_dequeue(q, &y), false);

    expect_bool("enqueue 10", queue_enqueue(q, 10), true);
    expect_bool("enqueue 20", queue_enqueue(q, 20), true);
    expect_bool("enqueue 30", queue_enqueue(q, 30), true);

    expect_size("queue_length(after enq)", queue_length(q), 3);
    expect_bool("queue_is_empty(after enq) == false", queue_is_empty(q), false);

    expect_bool("queue_peek == true", queue_peek(q, &y), true);
    expect_int("queue_peek value", y, 10);

    // FIFO: 10, 20, 30
    expect_bool("dequeue #1", queue_dequeue(q, &y), true);
    expect_int("dequeue #1 value", y, 10);

    expect_bool("dequeue #2", queue_dequeue(q, &y), true);
    expect_int("dequeue #2 value", y, 20);

    expect_size("queue_length(after 2 deq)", queue_length(q), 1);

    expect_bool("dequeue #3", queue_dequeue(q, &y), true);
    expect_int("dequeue #3 value", y, 30);

    expect_size("queue_length(empty again)", queue_length(q), 0);
    expect_bool("queue_is_empty(empty again)", queue_is_empty(q), true);

    expect_bool("dequeue(empty again) == false", queue_dequeue(q, &y), false);

    queue_free(q);
}

int main(void) {

    /* ---------- Queue Demo ---------- */

    Queue* qdemo = queue_new();
    if (!qdemo) {
        printf("queue_new failed\n");
        return 1;
    }

    queue_enqueue(qdemo, 10);
    queue_enqueue(qdemo, 20);
    queue_enqueue(qdemo, 30);

    printf("\nQueue length: %zu\n", queue_length(qdemo));
    queue_print(qdemo);

    int out = 0;
    if (queue_dequeue(qdemo, &out)) printf("Dequeue: %d\n", out);
    if (queue_dequeue(qdemo, &out)) printf("Dequeue: %d\n", out);

    printf("Queue length after dequeue: %zu\n", queue_length(qdemo));
    queue_print(qdemo);

    queue_free(qdemo);


    /* ---------- Stack Demo ---------- */

    Stack* stack = stack_new();
    if (!stack) {
        printf("stack_new failed\n");
        return 1;
    }

    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);

    printf("\nStack length: %zu\n", stack_length(stack));
    stack_print(stack);

    int v = 0;
    if (stack_pop(stack, &v)) printf("Pop: %d\n", v);
    if (stack_pop(stack, &v)) printf("Pop: %d\n", v);

    printf("Stack length after pop: %zu\n", stack_length(stack));
    stack_print(stack);

    stack_free(stack);


    /* ---------- Tests ---------- */

    run_tests();

    return 0;
}