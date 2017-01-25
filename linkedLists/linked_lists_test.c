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

struct Node * prep_base_list() {
    struct Node* result = create_node(0);

    for (int i = 1; i < 10; ++i) {
        add_last(result, i);
    }
    
    return result;
}

struct Node * prep_remove_duplication_test_case() {
    struct Node* test_case = create_node(0);

    for (int i = 1; i < 10; ++i) {
        add_last(test_case, i);
        if (i == 5 || i == 2) {
            add_last(test_case, i);
        }
    }
    add_last(test_case, 0);
    
    return test_case;
}

void remove_duplications_test() {
    struct Node* result = prep_base_list();
    struct Node* test_case = prep_remove_duplication_test_case();

    remove_duplications(test_case);
    assert(1 == compare_lists(result, test_case));
    
    clear(result);
    clear(test_case);
    printf("Duplication removing: OK!\n");
}

void kth_to_last_test() {
    struct Node* test_case = prep_base_list();

    assert(9 == kth_to_last(test_case, 1));
    assert(8 == kth_to_last(test_case, 2));
    assert(5 == kth_to_last(test_case, 5));
    assert(0 == kth_to_last(test_case, 10));
    assert(-1 == kth_to_last(test_case, 15));

    clear(test_case);
    printf("Kth to last: OK!\n");
}

struct Node* prep_delete_node_result() {
    struct Node* result = create_node(0);    

    for (int i = 1; i < 10; ++i) {
        if (i != 5) add_last(result, i);
    }

    return result;
}

struct Node* prep_sixth_node(struct Node* head) {
    struct Node* sixth_node = head;
    while (sixth_node->data != 5) sixth_node = sixth_node->next;
    return sixth_node;
}

void delete_node_test() {
    struct Node* test_case = prep_base_list();
    struct Node* result = prep_delete_node_result();
    struct Node* sixth_node = prep_sixth_node(test_case);

    delete_node(sixth_node);
    assert(1 == compare_lists(result, test_case));
    clear(test_case);
    clear(result);
    printf("Delete node from the middle: OK!\n");
}

struct Node* prep_list_partition_test_case() {
    struct Node* test_case = create_node(3);

    add_last(test_case, 5);
    add_last(test_case, 8);
    add_last(test_case, 5);
    add_last(test_case, 10);
    add_last(test_case, 2);
    add_last(test_case, 1);

    return test_case;
}

struct Node* prep_list_partition_result_recursive() {
    struct Node* result = create_node(3);

    add_last(result, 2);
    add_last(result, 1);
    add_last(result, 10);
    add_last(result, 5);
    add_last(result, 8);
    add_last(result, 5);

    return result;
}

struct Node* prep_list_partition_result() {
    struct Node* result = create_node(1);

    add_last(result, 2);
    add_last(result, 3);
    add_last(result, 5);
    add_last(result, 8);
    add_last(result, 5);
    add_last(result, 10);

    return result;
}

void list_partition_recusive_test() {
    struct Node* test_case = prep_list_partition_test_case();
    struct Node* result = prep_list_partition_result_recursive();

    test_case = list_partition_recursive(test_case, 5);
    assert(1 == compare_lists(result, test_case));

    clear(test_case);
    clear(result);
    printf("List Partition Recursive: OK!\n");
}

void list_partition_test() {
    struct Node* test_case = prep_list_partition_test_case();
    struct Node* result = prep_list_partition_result();

    test_case = list_partition(test_case, 5);
    assert(1 == compare_lists(result, test_case));

    clear(test_case);
    clear(result);
    printf("List Partition Iterative: OK!\n");
}

struct Node* prep_list_of_numb(int num[], int length) {
    struct Node* r = create_node(num[0]);
    for (int i = 1; i < length; ++i) add_last(r, num[i]);
    return r;
}

void sum_lists_reverse_test() {
    struct Node* test1 = prep_list_of_numb((int[3]){7, 1, 6}, 3);
    struct Node* test2 = prep_list_of_numb((int[3]){5, 9, 2}, 3);
    struct Node* result = prep_list_of_numb((int[3]){2, 1, 9}, 3);
    
    struct Node* comp = sum_lists_reverse(test1, test2);
    assert(1 == compare_lists(result, comp));

    clear(test1);
    clear(test2);
    clear(result);
    printf("Reverse numbers summation: OK!\n");
}

void sum_lists_reverse_rec_test() {
    struct Node* test1 = prep_list_of_numb((int[3]){7, 1, 6}, 3);
    struct Node* test2 = prep_list_of_numb((int[3]){5, 9, 2}, 3);
    struct Node* result = prep_list_of_numb((int[3]){2, 1, 9}, 3);
    
    struct Node* comp;
    comp = sum_lists_reverse_rec(test1, test2, 0);
    assert(1 == compare_lists(result, comp));
    clear(test1);
    clear(test2);
    clear(result);
    printf("Reverse numbers summation recursive: OK!\n");
}

int main() {
    remove_duplications_test();
    kth_to_last_test();
    delete_node_test();
    list_partition_recusive_test();
    list_partition_test();
    sum_lists_reverse_test();
    sum_lists_reverse_rec_test();
    
    return 0;
}
