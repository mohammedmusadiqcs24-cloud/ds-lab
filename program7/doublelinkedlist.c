#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert to the left of a node with given value
void insertLeft(struct Node** head, int target, int data) {
    struct Node* temp = *head;
    while (temp && temp->data != target) temp = temp->next;
    if (!temp) return; // target not found
    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev) temp->prev->next = newNode;
    else *head = newNode; // inserting before head
    temp->prev = newNode;
}

// Delete node by value
void deleteNode(struct Node** head, int target) {
    struct Node* temp = *head;
    while (temp && temp->data != target) temp = temp->next;
    if (!temp) return; // not found
    if (temp->prev) temp->prev->next = temp->next;
    else *head = temp->next; // deleting head
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create list: 10 -> 20 -> 30
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printf("Initial list: ");
    display(head);

    // Insert 15 to the left of 20
    insertLeft(&head, 20, 15);
    printf("After inserting 15 left of 20: ");
    display(head);

    // Delete node with value 30
    deleteNode(&head, 30);
    printf("After deleting 30: ");
    display(head);

    return 0;
}
