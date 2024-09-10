#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
public:
    Node* head;

    LinkedList() { head = NULL; }

    ~LinkedList() {
        Node* current = head;
        Node* next;
        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    bool isempty() { return (head == NULL); }

    void insertFirst(int newvalue)
    {
        Node* newnode = new Node();
        newnode->data = newvalue;
        newnode->next = head;
        head = newnode;
    }

    void Display()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;  // Newline for better output formatting
    }

    int count()
    {
        int countr = 0;
        Node* temp = head;
        while (temp != NULL)
        {
            countr++;
            temp = temp->next;
        }
        return countr;
    }

    bool isfound(int key)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void insertbefore(int item, int newvalue)
    {
        if (isempty())
            insertFirst(newvalue);

        if (!isfound(item))
        {
            cout << "Sorry, item not found\n";
            return;
        }

        Node* newnode = new Node();
        newnode->data = newvalue;

        // Case 1: Item is at the head
        if (head->data == item)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL && temp->data != item)
        {
            prev = temp;
            temp = temp->next;
        }

        // Insert before the found item
        if (temp != NULL) // temp is the node containing 'item'
        {
            prev->next = newnode;
            newnode->next = temp;
        }
    }
    void append(int newvalue)
    {
        if (isempty())
            insertFirst(newvalue);
        else
        {

        }
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node* newnode = new Node();
        newnode->data = newvalue;
        temp->next = newnode;
        newnode->next = NULL;
    }
    void Delete(int item)
    {
        if (isempty())
            cout << "no item to delete\n";
        Node* delptr = head;
        if (head->data == item)
        {
            head = head->next;
            delete delptr;
        }
        else
        {
            Node* prev = NULL;
            delptr = head;
            while (delptr->data != item)
            {
                prev = delptr;
                delptr = delptr->next;
            }
            prev->next = delptr->next;
            delete delptr;
        }
    }
};

int main()
{
    LinkedList lst;

    int item;
    int n;

    cout << "How many items do you want to insert in the list?\n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter item to insert in the list: ";
        cin >> item;
        lst.insertFirst(item);
    }

    cout << "\nThe list contains: " << lst.count() << " items." << endl;
    lst.Display();

    /*cout << "Enter item to search for: ";
    cin >> item;

    if (lst.isfound(item))
        cout << "Item found\n";
    else
        cout << "Item not found\n";*/

   /* int newvlue;*/
    cout << "Enter item to delete: ";
    cin >> item;

   /* lst.insertbefore(item, newvalue);*/
   /* lst.append(newvalue);*/
    lst.Delete(item);
    cout << "\nThe updated list contains: " << lst.count() << " items." << endl;
    lst.Display();


}
