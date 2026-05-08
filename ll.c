#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void pop_back() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* EP1 = head;

    while (EP1->next->next != NULL)

    {
        EP1 = EP1->next;
    }
    struct Node* EP2 = EP1->next;
    EP1->next = NULL;
    free(EP2);
}

void pop_pos(int pos) {

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node* EP1 = head;
    for(int i = 1; i < pos - 1; i++) {
        if(EP1->next == NULL) {
            printf("Invalid position\n");
            return;
        }
        EP1 = EP1->next;
    }
    struct Node* EP2 = EP1->next;
    EP1->next = EP2->next;
    free(EP2);
}

void display() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    head = createNode(1);
    head->next = createNode(2);

    printf("Original List: ");
    display();

    pop_back();
    printf("After pop_back: ");
    display();

    return 0;
}