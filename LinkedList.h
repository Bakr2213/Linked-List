#pragma once
class LinkedList
{
public:
    Node* head;

    LinkedList();

    ~LinkedList();

    bool isempty();

    void insertFirst(int newvalue);

    void Display();

    int count();

    bool isfound(int key);

    void insertbefore(int item, int newvalue);
    void append(int newvalue);
    void Delete(int item);
};

