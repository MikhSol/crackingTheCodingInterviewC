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
