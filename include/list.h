#ifndef LIST_H
#define LIST_H

#include <stddef.h> // size_t

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Insert
Node* list_push_front(Node* head, int value);
Node* list_push_back(Node* head, int value);

// Search / delete
Node* list_find(Node* head, int value);
Node* list_delete(Node* head, int value);

// Utilities
size_t list_length(Node* head);
void list_print(const Node* head);
void list_free(Node* head);

#endif // LIST_H