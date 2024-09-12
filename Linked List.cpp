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
