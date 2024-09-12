#include <iostream>
using namespace std;
#include "LinkedList.h"
#include "Node.h"
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

    cout << "Enter item to search for: ";
    cin >> item;

    if (lst.isfound(item))
        cout << "Item found\n";
    else
        cout << "Item not found\n";

    int newvalue=0;
    cout << "Enter item to delete: ";
    cin >> item;
    lst.Delete(item);

    cout << "\nThe list contains: " << lst.count() << " items." << endl;
    lst.Display();

    cout << "Enter value to insert at the beginning: ";
    cin >> newvalue;
    lst.insertFirst(newvalue);
    cout << newvalue << " inserted at the beginning.\n";


    cout << "Enter value to append: ";
    cin >> newvalue;
    lst.append(newvalue);
    cout << newvalue << " appended to the list.\n";


    cout << "Enter the value to insert before: ";
    cin >> item;
    cout << "Enter new value to insert: ";
    cin >> newvalue;
    lst.insertbefore(item, newvalue);

    cout << "\nThe list contains: " << lst.count() << " items." << endl;
    lst.Display();



}
