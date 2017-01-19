//solutions.h

#include "../../c_double_linked_list/double_linked_list.h"

void remove_duplications(struct Node* head);
int kth_to_last(struct Node* head, int k);
void delete_node(struct Node* node);
struct Node* list_partition_recursive(struct Node* head, int x);
struct Node* list_partition(struct Node* node, int x);
