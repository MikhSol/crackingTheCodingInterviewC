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


int main()
{
    head = createNode(0);
    printList();

    for (int i=1; i<10; ++i) {
        if (i % 2 == 0) {
            insertToHead(i);
        } else {
            insertToTail(i);
        }
    }
    printList();
    
    head = NULL;
    insertToHead(100);
    printList();

    head = NULL;
    insertToTail(101);
    printList();

    return 0;
}
