#include "clsDblLinkedList.h"

int main()
{
    clsDblLinkedList <int> MyLinkedList;

    MyLinkedList.InsertAtBeginning(5);
    MyLinkedList.InsertAtBeginning(4);
    MyLinkedList.InsertAtBeginning(3);
    MyLinkedList.InsertAtBeginning(2);
    MyLinkedList.InsertAtBeginning(1);
    // MyLinkedList.Reverse();
    MyLinkedList.PrintList();
    
    MyLinkedList.InsertAfter(4,1000);
    MyLinkedList.PrintList();
    // system("pause > 0");
    return 0;
}