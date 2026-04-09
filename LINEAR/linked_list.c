#include <stdio.h>
#include <stdlib.h>


typedef struct Node 
{
    int value;
    struct Node *next;
} Node;

Node* createNode(int value){
    Node* node = malloc(sizeof(Node));
    
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->value = value;
    node->next = NULL;

    return node;
}

void insert(Node** head, int value){

    Node* newNode = createNode(value);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node* current = *head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}

void delete(Node** head, int value){
    Node* current = *head;
    Node* prev = NULL;

    while(current != NULL){
        if (current->value == value) {
            if(prev == NULL){
                *head = current->next;
            }else{
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

Node* search(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->value == value)
            return current;
        current = current->next;
    }
    return NULL;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    printf("List after insertion:\n");
    printList(head);

    Node* found = search(head, 20);
    if (found)
        printf("Found: %d\n", found->value);
    else
        printf("Value not found\n");

    delete(&head, 20);
    printf("List after deleting 20:\n");
    printList(head);

    freeList(head);

    return 0;
}
