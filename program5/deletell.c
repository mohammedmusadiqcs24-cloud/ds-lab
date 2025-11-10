#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* head = NULL;

// Create and insert at end
void createNode(int data) {
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Display the list
void displayList() {
    node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete first element
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* temp = head;
    head = head->next;
    free(temp);
    printf("First element deleted.\n");
}

// Delete specified element by value
void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* temp = head;
    node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Element %d deleted.\n", value);
}

// Delete last element
void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last element deleted.\n");
        return;
    }

    node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    printf("Last element deleted.\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Create Node\n");
        printf("2. Display List\n");
        printf("3. Delete First Element\n");
        printf("4. Delete Element by Value\n");
        printf("5. Delete Last Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                createNode(data);
                break;
            case 2:
                displayList();
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteByValue(data);
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}                                                                                                      
