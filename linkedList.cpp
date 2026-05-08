#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    long long data;
    Node *next;

    Node(long long val)
    {
        data = val;
        next = NULL;
    }
};

// Linked List class
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(long long val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(long long val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // 🔹 Insert at N-th position
    void insertAtPosition(long long val, long long pos)
    {
        Node *newNode = new Node(val);

        // Position 1 → beginning
        if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;

        // Traverse to (pos-1)th node
        for (long long i = 1; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid position\n";
                delete newNode;
                return;
            }
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid position\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a node
    void deleteNode(long long val)
    {
        if (head == NULL)
            return;

        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL && temp->next->data != val)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Value not found\n";
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Display list
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "Still learning\n";
    }
};

// Main function
int main()
{
    LinkedList ll;

    ll.insertAtEnd(5);
    ll.insertAtEnd(3);
    ll.insertAtEnd(3);
    ll.insertAtEnd(52);
    ll.insertAtEnd(16);
    ll.insertAtPosition(12, 6);
    ll.insertAtPosition(2025000000013, 7);
    ll.deleteNode(3);


    cout << "The class roll sequence since I started studying: ";
    ll.display();

    return 0;
}