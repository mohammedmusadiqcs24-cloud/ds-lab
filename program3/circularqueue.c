#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int items[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty !!\n");
    } else {
        printf("Queue is : \n");
        int i = front;
        while (1) {
            printf("%d  ", items[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

void enQueue(int element) {
    if (isFull()) {
        printf("Queue is Full!!\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        items[rear] = element;
        printf("Inserted element: %d\n", element);
    }
}

void deQueue() {
    if (isEmpty()) {
        printf("Queue is Empty !!\n");
    } else {
        int deleted = items[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("Deleted item is : %d\n", deleted);
    }
}

int main() {
    int choice, elem;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter Your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                enQueue(elem);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited successfully\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
