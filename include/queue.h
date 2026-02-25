#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct Queue Queue;

Queue* queue_new(void);
void queue_free(Queue* q);

size_t queue_length(const Queue* q);
bool queue_is_empty(const Queue* q);

bool queue_enqueue(Queue* q, int value);
bool queue_dequeue(Queue* q, int* out_value);
bool queue_peek(const Queue* q, int* out_value);

void queue_print(const Queue* q);

#endif // QUEUE_H