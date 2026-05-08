#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Enqueue function
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) front = 0; // first element
        queue[++rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Dequeue function
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to dequeue\n");
    } else {
        printf("%d dequeued from queue\n", queue[front++]);
        if (front > rear) front = rear = -1; // reset queue if empty
    }
}

// Peek front element
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Display queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Queue elements:\n");
        do {
            printf("%d\n", queue[i]);
            i++;
        } while(i <= rear);
    }
}

int main() {
    int choice, value;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 5);

    return 0;
}