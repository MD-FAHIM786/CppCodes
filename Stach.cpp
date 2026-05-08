#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if stack is full
int isFull() {
    return top == MAX - 1;
}

// Push function
void push(int item) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", item);
    } else {
        stack[++top] = item;
        printf("%d pushed to stack\n", item);
    }
}

// Pop function
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Nothing to pop\n");
    } else {
        int popped = stack[top--];
        printf("%d popped from stack\n", popped);
    }
}

// Peek function (top element)
void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Display function
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
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