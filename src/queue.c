#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int* data;
    size_t size;      // Anzahl Elemente
    size_t capacity;  // reservierte Plätze
    size_t head;      // Index vom vordersten Element
    size_t tail;      // Index wo als nächstes eingefügt wird
};

static bool queue_grow(Queue* q) {
    size_t new_cap = (q->capacity == 0) ? 4 : (q->capacity * 2);
    int* new_data = (int*)malloc(new_cap * sizeof(int));
    if (!new_data) return false;

    // Elemente in logischer Reihenfolge kopieren (head -> tail)
    for (size_t i = 0; i < q->size; i++) {
        new_data[i] = q->data[(q->head + i) % q->capacity];
    }

    free(q->data);
    q->data = new_data;
    q->capacity = new_cap;
    q->head = 0;
    q->tail = q->size;
    return true;
}

Queue* queue_new(void) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) return NULL;

    q->data = NULL;
    q->size = 0;
    q->capacity = 0;
    q->head = 0;
    q->tail = 0;

    return q;
}

void queue_free(Queue* q) {
    if (!q) return;
    free(q->data);
    free(q);
}

size_t queue_length(const Queue* q) {
    return q ? q->size : 0;
}

bool queue_is_empty(const Queue* q) {
    return !q || q->size == 0;
}

bool queue_enqueue(Queue* q, int value) {
    if (!q) return false;

    if (q->capacity == 0) {
        // Erstes Wachstum von 0 -> 4
        q->capacity = 4;
        q->data = (int*)malloc(q->capacity * sizeof(int));
        if (!q->data) {
            q->capacity = 0;
            return false;
        }
        q->head = 0;
        q->tail = 0;
    }

    if (q->size == q->capacity) {
        if (!queue_grow(q)) return false;
    }

    q->data[q->tail] = value;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
    return true;
}

bool queue_dequeue(Queue* q, int* out_value) {
    if (!q || q->size == 0) return false;

    if (out_value) {
        *out_value = q->data[q->head];
    }
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return true;
}

bool queue_peek(const Queue* q, int* out_value) {
    if (!q || q->size == 0) return false;
    if (out_value) {
        *out_value = q->data[q->head];
    }
    return true;
}

void queue_print(const Queue* q) {
    if (!q || q->size == 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (size_t i = 0; i < q->size; i++) {
        int v = q->data[(q->head + i) % q->capacity];
        printf("%d", v);
        if (i + 1 < q->size) printf(", ");
    }
    printf("]\n");
}