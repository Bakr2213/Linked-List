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
	LinkedList()
	{
		head = NULL;
	}
	bool isempty()
	{
		return (head == NULL);
	}
	void insertFirst(int newvalue)
	{
		Node* newnod;
		newnod->data = newvalue;
		if (isempty())
		{
			newnod->next = NULL;
			head = newnod;
		}
		else
		{
			newnod->next = head;
			head = newnod;
		}
	}

	void Display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	int count()
	{
		int countr;
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
		bool found = false;
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == key)
				found = true;
		}
		return found;
	}
};

int main()
{
	LinkedList lst;
	if (lst.isempty())
		cout << "list is empty \n";
	else
		cout << "the list containes : " << lst.count() << endl;
	int item;
	cout << "enter item to insert in the list \n";
	cin >> item;
	lst.insertFirst(item);
	lst.Display();
	cout << "enter item to insert in the list \n";
	cin >> item;
	lst.insertFirst(item);
	lst.Display();
	cout << "enter item to insert in the list \n";
	cin >> item;
	lst.insertFirst(item);
	lst.Display();
	cout << "the list containes : " << lst.count() << endl;

	cout << "enter item to search in the list \n";
	cin >> item;
	if (lst.isfound(item))
		cout << "item found \n";
	else 
		cout << "item not found \n";
}

