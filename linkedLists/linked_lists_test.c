//tests for linked lists tasks from the "Cracking The Coding Interview".

#include <assert.h>
#include <stdbool.h>
#include "../../c_double_linked_list/double_linked_list.h"

int main()
{
    struct Node* h = initHeadNode(0);
    printList(h);
    clear(h);
    
    return 0;
}
