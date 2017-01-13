//linked_list.c

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void initHeadNoad(int data) {
    head = createNode(data);
}

void insertToHead(int data) {
    struct Node* node = createNode(data);
    if (head == NULL) {
        head = node;
        return;
    }
    head->prev = node;
    node->next = head;
    head = node;
}

void insertToTail(int data) {
    struct Node* node = createNode(data);
    if (head == NULL) {
        head = node;
        return;
    }
    struct Node* current = head;
    while (current->next != NULL) current = current->next;
    current->next = node;
    node->prev = current;
}

void printList() {
    printf("\n[ ");
    struct Node* node = head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("]\n");
}

void removeList() {
    if (head == NULL) {
        printf("There are no head node defined!\n");
        return;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        struct Node* tmp = current->next;
        free(current);
        current = tmp;
    }
    head = NULL;
    printf("List was removed!\n");
}

void removeNode(struct Node* node) {
    if (head == node) {
        printf("Head node\n");
        struct Node* tmp = head;
        head = head->next;
        free(head);
    } else {
        node->prev->next = node->next;
        if (node->next != NULL) node->next->prev = node->prev;
        free(node);
    }
    printf("Node was removed!\n");
}


int main()
{
    removeList();
    head = createNode(0);
    printList();

    head = createNode(5);
    printList();
    removeNode(head);

    head = createNode(5);
    printList();
    insertToTail(6);
    printList();
    struct Node* n = head->next;
    removeNode(n);
    printList();

    for (int i=1; i<10; ++i) {
        if (i % 2 == 0) {
            insertToHead(i);
        } else {
            insertToTail(i);
        }
    }
    printList();
    removeList();
    
    insertToHead(100);
    printList();
    removeList();

    insertToTail(101);
    printList();
    removeList();

    return 0;
}
