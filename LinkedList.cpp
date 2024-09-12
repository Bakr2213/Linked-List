#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

bool LinkedList::isempty() {
    return (head == nullptr);
}

void LinkedList::insertFirst(int newvalue) {
    Node* newnode = new Node();
    newnode->data = newvalue;
    newnode->next = head;
    head = newnode;
}

void LinkedList::Display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;  // Newline for better output formatting
}

int LinkedList::count() {
    int countr = 0;
    Node* temp = head;
    while (temp != nullptr) {
        countr++;
        temp = temp->next;
    }
    return countr;
}

bool LinkedList::isfound(int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void LinkedList::insertbefore(int item, int newvalue) {
    if (isempty()) {
        insertFirst(newvalue);
        return;
    }

    if (!isfound(item)) {
        cout << "Sorry, item not found\n";
        return;
    }

    Node* newnode = new Node();
    newnode->data = newvalue;

    // Case 1: Item is at the head
    if (head->data == item) {
        newnode->next = head;
        head = newnode;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->data != item) {
        prev = temp;
        temp = temp->next;
    }

    // Insert before the found item
    if (temp != nullptr) { // temp is the node containing 'item'
        prev->next = newnode;
        newnode->next = temp;
    }
}

void LinkedList::append(int newvalue) {
    if (isempty()) {
        insertFirst(newvalue);
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    Node* newnode = new Node();
    newnode->data = newvalue;
    temp->next = newnode;
    newnode->next = nullptr;
}

void LinkedList::Delete(int item)
{
    if (isempty()) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Case 1: If the node to be deleted is the head
    if (head->data == item) {
        head = head->next;
        delete temp; // free the old head
        return;
    }

    // Traverse the list to find the node to delete
    while (temp != nullptr && temp->data != item) {
        prev = temp;
        temp = temp->next;
    }

    // Case 2: Node not found
    if (temp == nullptr) {
        cout << "Value not found in the list." << endl;
        return;
    }

    // Case 3: Node is found (temp now points to the node to delete)
    prev->next = temp->next; // Unlink the node from the list
    delete temp; // Free memory
}
