#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    // Insert at beginning
    void push_front(int val)
    {
        Node *NN = new Node(val);

        if (head == NULL)
        {
            head = NN;
            return;
        }

        NN->next = head;
        head->prev = NN;
        head = NN;
    }

    // Insert at end
    void push_back(int val)
    {
        Node *NN = new Node(val);

        if (head == NULL)
        {
            head = NN;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = NN;
        NN->prev = temp;
    }

    // Insert at position (1-based)
    void push_pos(int val, int pos)
    {
        if (pos == 1)
        {
            push_front(val);
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid Position\n";
            return;
        }

        Node *NN = new Node(val);

        NN->next = temp->next;
        NN->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = NN;
        }

        temp->next = NN;
    }

    // Delete first node
    void pop_front()
    {
        if (head == NULL)
            return;

        Node *del = head;

        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete del;
    }

    // Delete last node
    void pop_back()
    {
        if (head == NULL)
            return;

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }

    // Delete at position (1-based)
    void pop_pos(int pos)
    {
        if (head == NULL)
            return;

        if (pos == 1)
        {
            pop_front();
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid Position\n";
            return;
        }

        temp->prev->next = temp->next;

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.push_back(5);
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    dll.push_back(40);
    dll.push_back(50);

    dll.display();

    dll.push_pos(25, 4);
    dll.display();

    dll.pop_front();
    dll.display();

    dll.pop_back();
    dll.display();

    dll.pop_pos(3);
    dll.display();

    return 0;
}