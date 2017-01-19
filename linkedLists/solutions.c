//solutions.c

#include <stddef.h>
#include <stdio.h>
#include "solutions.h"
#include "../../c_double_linked_list/double_linked_list.h"

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void remove_duplications(struct Node* head) {
    struct Node* current = head;
    while (current->next != NULL) {
        struct Node* next = current->next;
        while (next->next != NULL) {
            if (current->data == next->data) clear_node(head, next);
            next = next->next;
        }
        if (current->data == next->data) clear_node(head, next);
        current = current->next;
    }
}

int kth_to_last(struct Node* head, int k) {
    int len = length(head);
    if (k > len) return -1;
    int i = len - k;
    struct Node* current = head;
    while (i > 0) {
        i--;
        current = current->next;        
    }
    return current->data;
}

void delete_node(struct Node* node) {
    if (node->next != NULL) {
        node->data = node->next->data;
        node->next = node->next->next;
    }
}
