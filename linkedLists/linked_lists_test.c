//tests for linked lists tasks from the "Cracking The Coding Interview".

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../c_double_linked_list/double_linked_list.h"
#include "solutions.h"

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void remove_duplications_test() {
    struct Node* result = create_node(0);
    struct Node* test_case = create_node(0);

    for (int i = 1; i < 10; ++i) {
        add_last(result, i);
        add_last(test_case, i);
        if (i == 5 || i == 2) {
            add_last(test_case, i);
        }
    }
    add_last(test_case, 0);

    remove_duplications(test_case);
    assert(1 == compare_lists(result, test_case));
    
    clear(result);
    clear(test_case);
    printf("Duplication removing: OK!\n");
}

void kth_to_last_test() {
    struct Node* test_case = create_node(0);

    for (int i = 1; i < 10; ++i) {
        add_last(test_case, i);
    }

    assert(9 == kth_to_last(test_case, 1));
    assert(8 == kth_to_last(test_case, 2));
    assert(5 == kth_to_last(test_case, 5));
    assert(0 == kth_to_last(test_case, 10));
    assert(-1 == kth_to_last(test_case, 15));
    clear(test_case);
    printf("Kth to last: OK!\n");
}

void delete_node_test() {
    struct Node* test_case = create_node(0);
    struct Node* result = create_node(0);    

    for (int i = 1; i < 10; ++i) {
        add_last(test_case, i);
        if (i != 5) add_last(result, i);
    }

    struct Node* sixth_node = test_case;
    while (sixth_node->data != 5) sixth_node = sixth_node->next;

    delete_node(sixth_node);
    assert(1 == compare_lists(result, test_case));
    printf("Delete node from the middle: OK!\n");
}


int main() {
    remove_duplications_test();
    kth_to_last_test();
    delete_node_test();
    
    return 0;
}
