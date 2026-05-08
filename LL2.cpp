#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node(int val)
   {
      data = val;
      next = NULL;
   }
};

class List
{
   Node *head;
   Node *tail;

public:
   List()
   {
      head = tail = NULL;
   }

   void push_front(int val)
   {
      Node *newNode = new Node(val);
      if (head == NULL)
      {
         head = tail = newNode;
         return;
      }
      else
      {
         newNode->next = head;
         head = newNode;
      }
   }

   void push_back(int val)
   {
      Node *newNode = new Node(val);
      if (head == NULL)
      {
         head = tail = newNode;
         return;
      }
      else
      {
         tail->next = newNode;
         tail = newNode;
      }
   }

   void print_ll()
   {
      Node *temp = head;
      while (temp != NULL)
      {
         cout << temp->data << "->";
         temp = temp->next;
      }

      cout << "Still Studying\n"
           << endl;
   }

   void pop_front()
   {
      if (head == NULL)
      {
         cout << "List is empty\n";
         return;
      }
      else
      {
         Node *temp = head;
         head = head->next;
         temp->next = NULL;
         delete temp;
      }
   }

   void pop_back()
   {
      if (head == NULL)
      {
         cout << "List is empty\n";
         return;
      }
      else
      {
         Node *temp = head;
         while (temp->next != tail)
         {
            temp = temp->next;
         }
         temp->next = NULL;
         delete tail;
         tail = temp;
      }
   }

   void insertAtPos(int val, int pos)
   {

      if (pos < 0)
         return;

      if (pos == 0)
      {
         push_front(val);
         return;
      }

      if (head == NULL)
      {
         cout << "List is empty\n";
         return;
      }

      Node *newNode = new Node(val);
      Node *temp = head;
      for (int i = 0; i < pos - 1; i++)
      {
         if (temp->next == NULL)
            break;
         temp = temp->next;
      }
      newNode->next = temp->next;
      temp->next = newNode;
      if (newNode->next == NULL)
         tail = newNode;
   }

   void deleteAtPos(int pos)
   {
      if (pos < 0)
         return;

      if (pos == 0)
      {
         pop_front();
         return;
      }
      if (head == NULL)
      {
         cout << "List is empty\n";
         return;
      }
      Node *temp = head;
      for (int i = 0; i < pos - 1; i++)
      {
         if (temp->next == NULL)
            return;
         temp = temp->next;
      }
      Node *nodeToDelete = temp->next;
      temp->next = temp->next->next;
      delete nodeToDelete;
      if (temp->next == NULL)
         tail = temp;
   }


   int search(int key) {
      Node *temp = head;
      int idx = 0;
      while(temp != NULL) {
         if(temp->data == key) {
            return idx;
         }
         temp = temp->next;
         idx++;
      }
      return -1; // Key not found
   }
};

int main()
{
   List ll;

   ll.push_front(5);
   ll.push_front(9);
   ll.push_back(3);
   ll.push_back(52);
   ll.push_back(16);
   ll.push_back(12);
   ll.push_back(13);

   cout << "This is my roll sequence: ";
   ll.print_ll();
   ll.pop_front();
   ll.pop_back();
   cout << "After popping front and back: ";
   ll.print_ll();

   ll.insertAtPos(42,5);
   cout << "After inserting: ";
   ll.print_ll();

   ll.deleteAtPos(3);
   cout << "After deleting: ";
   ll.print_ll();

   cout << "Index of 5: " << ll.search(5) << endl;

   return 0;
}
