#include <stdio.h>
#include <stdlib.h>  // Needed for exit()

#define SIZE 3

int queue_array[SIZE];
int front = -1, rear = -1;

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty !!\n");
    } else {
        printf("Queue is : \n");
        for (int i = front; i <= rear; i++) {
            printf("%d  ", queue_array[i]);
        }
        printf("\n");
    }
}

void insert() {
    int add_item;
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
    } else {
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue_array[rear] = add_item;
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow !!\n");
    } else {
        printf("Deleted item is : %d\n", queue_array[front]);
        front++;
        if (front > rear) {
            // Reset queue after last deletion
            front = rear = -1;
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter Your choice : ");
        scanf("%d", &choice);  // Removed space after %d

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited successfully\n");
                exit(0);  // Use exit(0) for normal termination
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
