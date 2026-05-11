#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void push_front(int val) {
    struct Node* newNode = createNode(val);
    if(head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void push_back(int val) {
    struct Node* newNode = createNode(val);
    if(head == NULL) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void push_pos(int val, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        push_front(val);
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        if (temp == NULL)
        {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    if (temp->next == NULL)
    {
        push_back(val);
        return;
    }

    struct Node *newNode = createNode(val);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

void pop_front() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if(head == NULL) {
        tail = NULL;
    } else {
        head->prev = NULL;
    }
    free(temp);
}

void pop_back() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = tail;
    tail = tail->prev;
    if(tail == NULL) {
        head = NULL;
    } else {
        tail->next = NULL;
    }
    free(temp);
}

void pop_pos(int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos == 1)
    {
        pop_front();
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    if (temp->next == NULL)
    {
        pop_back();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

        void printList()
        {
            struct Node *temp = head;
            while (temp != NULL)
            {
                printf("%d <=> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
        }
int main()
{
    push_front(10);
    push_front(20);
    push_back(30);
    push_back(40);
    printList();
    push_pos(25, 3);
    printList();
    pop_pos(3);
    printList();
    return 0;
}