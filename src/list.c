#include "list.h"
#include <stdio.h>
#include <stdlib.h> // malloc, free

static Node* node_create(int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) return NULL;
    n->value = value;
    n->next = NULL;
    return n;
}

Node* list_push_front(Node* head, int value) {
    Node* n = node_create(value);
    if (!n) return head; 
    n->next = head;
    return n;
}

Node* list_push_back(Node* head, int value) {
    Node* n = node_create(value);
    if (!n) return head;

    if (head == NULL) return n;

    Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = n;
    return head;
}

Node* list_find(Node* head, int value) {
    Node* cur = head;
    while (cur != NULL) {
        if (cur->value == value) return cur;
        cur = cur->next;
    }
    return NULL;
}

Node* list_delete(Node* head, int value) {
    Node* cur = head;
    Node* prev = NULL;

    while (cur != NULL) {
        if (cur->value == value) {
            if (prev == NULL) {
                // lösche head
                Node* new_head = cur->next;
                free(cur);
                return new_head;
            } else {
                prev->next = cur->next;
                free(cur);
                return head;
            }
        }
        prev = cur;
        cur = cur->next;
    }
    return head; // nichts gefunden -> unverändert
}

size_t list_length(Node* head) {
    size_t len = 0;
    Node* cur = head;
    while (cur != NULL) {
        ++len;
        cur = cur->next;
    }
    return len;
}

void list_print(const Node* head) {
    printf("[");
    const Node* cur = head;
    while (cur != NULL) {
        printf("%d", cur->value);
        if (cur->next != NULL) printf(", ");
        cur = cur->next;
    }
    printf("]\n");
}

void list_free(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
}