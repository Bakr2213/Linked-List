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
		Node* newnode = new Node();
		newnode->data = newvalue;
		if (isempty())
		{
			newnode->next = NULL;
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}

	void Display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl ;
			temp = temp->next;
		}
	}
	int count()
	{
		int countr=0;
		Node*temp = head;
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
				return true;  // Item found, return immediately
			temp = temp->next;
		}
		return false;  // Item not found
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
	int n; // number of items to insert

	cout << "How many items do you want to insert in the list? \n";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter item to insert in the list: ";
		cin >> item;
		lst.insertFirst(item);
	}
	lst.Display();
	cout << "the list contains : " << lst.count() << endl ;

	cout << "enter item to search for \n";
	cin >> item;
	if (lst.isfound(item))
		cout << "item found \n";
	else 
		cout << "item not found \n";
}

