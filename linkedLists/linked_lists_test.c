//tests for linked lists tasks from the "Cracking The Coding Interview".

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../c_double_linked_list/double_linked_list.h"
#include "solutions.h"

static void remove_duplications_test() {
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


int main() {
    remove_duplications_test();
    
    return 0;
}
