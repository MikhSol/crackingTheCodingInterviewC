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

struct Node* list_partition_recursive(struct Node* head, int x) {
    if (head->next != NULL) {
        struct Node* node = list_partition_recursive(head->next, x);
        if (head->data < x && node->data < x) {
            head->next = node;
            return head;
        }
        if (head->data >= x) {
            add_last(node, head->data);
            return node;
        }
        add_last(head, node->data);
        return head;
    }
    return head;
}

struct Node* list_partition(struct Node* node, int x) {
    struct Node* head = node;
    struct Node* tail = node;

    while (node != NULL) {
        struct Node* next = node->next;
        if (node->data < x) {
            node->next = head;
            head = node;
        } else {
            tail->next = node;
            tail = node;
        }
        node = next;
    }
    tail->next = NULL;
    return head;   
}

int get_number_from_reversed_list(struct Node* n) {
    struct Node* tmp = n;
    int sum = tmp->data;
    int i = 1;
    tmp = tmp->next;
    while (tmp != NULL) {
        sum += tmp->data * 10 * i;
        i *= 10;
        tmp = tmp->next;
    }
    return sum;
}

struct Node* sum_lists_reverse(struct Node* n1, struct Node* n2) {
    int sum = get_number_from_reversed_list(n1) +
        get_number_from_reversed_list(n2);
    int i = 1;
    struct Node* result;
    while (sum) {
        add_last(result, sum % 10);
        sum /= 10;
    }
    return result;
}

struct Node* sum_lists_reverse_rec(struct Node* n1, struct Node* n2, int incr) {        
    if (n1 == NULL && n2 == NULL && incr == 0) return NULL;
    struct Node* result = create_node(0);
    int val = incr;

    if (n1 != NULL) val += n1->data;
    if (n2 != NULL) val += n2->data;

    result->data = val % 10;
    if (n1 != NULL || n2 != NULL) {
        result->next = sum_lists_reverse_rec(n1 != NULL ? n1->next: NULL,
                                             n2 != NULL ? n2->next: NULL,
                                             val / 10);
    }
    return result;
}
