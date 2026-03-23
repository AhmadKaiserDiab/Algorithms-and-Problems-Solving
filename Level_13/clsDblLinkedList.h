#pragma once
#include <iostream>
using namespace std;

template <class T> 
class clsDblLinkedList
{
    public:
        class Node
        {
            public:
                T Value;
                Node *Next;
                Node *Previous;
        };

    private:
        short _Size = 0; 
        Node * Head = NULL;
        // Node * Tail = NULL;

    public:
        void PrintList()
        {
            Node* CurrentNode = Head;
            while (CurrentNode != NULL)
            {
                cout << CurrentNode->Value << "  ";
                CurrentNode = CurrentNode->Next;
            }
            cout<<"\n";
        }

        void InsertAtBeginning(T Value)
        {
            Node *newNode = new Node();
            newNode->Value = Value;
            newNode->Next = Head;
            newNode->Previous = NULL;
        
            if (Head != NULL)
            {
                Head->Previous = newNode;
            }
            Head = newNode;
            _Size++;
        }

        Node * Find(T Value)
        {
            Node* CurrentNode = Head;
            while (CurrentNode != NULL)
            {
                if(CurrentNode->Value == Value)
                {
                    return CurrentNode;
                }
                CurrentNode = CurrentNode->Next;
            }
            return NULL;
        }

        void InsertAfter(Node * CurrentNode , T NewValue )
        {
            if (CurrentNode == NULL)
            {
                cout << "The Given Previous Node Cannot Be NULL";
                return ;
            }
            Node * NewNode = new Node();
            NewNode->Value = NewValue;
            NewNode->Next = CurrentNode->Next;
            NewNode->Previous = CurrentNode;
            
            if(CurrentNode->Next != NULL)
            {
                CurrentNode->Next->Previous = NewNode;
            }
            CurrentNode->Next = NewNode;
            _Size++;
        }

        void InsertAtEnd(T Value)
        {
            Node * NewLastNode = new Node();
            NewLastNode->Value = Value;
            NewLastNode->Next = NULL;
            
            if(Head == NULL)
            {   
                NewLastNode->Previous = NULL;
                Head = NewLastNode;
            }
            else
            {
                Node * CurrentNode = Head;
                while (CurrentNode->Next != NULL)
                {
                    CurrentNode = CurrentNode->Next;
                }
                CurrentNode->Next = NewLastNode;
                NewLastNode->Previous = CurrentNode;
            }
            _Size++;
        }

        void DeleteNode(Node *&NodeToDelete )
        {
            if (Head == NULL || NodeToDelete == NULL)
            {
                return;
            }
            if (Head == NodeToDelete)
            {
                Head = NodeToDelete->Next;
            }
            if (NodeToDelete->Next != NULL)
            {
                NodeToDelete->Next->Previous = NodeToDelete->Previous;
            }
            if (NodeToDelete->Previous != NULL)
            {
                NodeToDelete->Previous->Next = NodeToDelete->Next;
            }
            delete NodeToDelete;
            _Size--;
        }

        void DeleteFirstNode()
        {
            if (Head == NULL)
            {
                return;
            }
            Node *Temp = Head;
            Head = Head->Next;
            if (Head != NULL)
            {
                Head->Previous = NULL;
            }
            delete Temp;
            _Size--;
        }

        void DeleteLastNode()
        {
            if (Head == NULL)
            {
                return;
            }
        
            if (Head->Next == NULL)
            {
                delete Head;
                Head = NULL;
                _Size--;
                return;
            }
        
            Node * CurrentNode = Head;
            while (CurrentNode-> Next->Next != NULL)
            {
                CurrentNode = CurrentNode->Next;
            }
            Node *Temp = CurrentNode->Next;
            CurrentNode->Next = NULL;
            delete Temp;
            _Size--;
        }

        int Size()
        {
            return _Size;
        }

        bool IsEmpty()
        {
            return _Size == 0;
        }

        void Clear()
        {
            while(_Size>0)
            {
                DeleteFirstNode();
            }
        }

        void Reverse()
        {
            Node * CurrentNode = Head;
            Node * Temp = nullptr;
            while (CurrentNode != NULL)
            {
                Temp = CurrentNode -> Previous;
                CurrentNode -> Previous = CurrentNode->Next;
                CurrentNode->Next = Temp;
                CurrentNode = CurrentNode->Previous;
            }
            if(Temp != nullptr)
            {
                Head = Temp->Previous;
            }
        }

        Node * GetNode(T Index)
        {
            Node * CurrentNode = Head;
            if(Index < 0 || Index >= _Size)
            {
                return NULL;
            }
            for(int i = 0 ; i<Index ; i++)
            {
                if(CurrentNode == NULL)
                {
                    break;
                }
                else
                {
                    CurrentNode = CurrentNode->Next;
                }
            }
            return CurrentNode;
        }

        T GetItem(short Index)
        {
            return GetNode(Index)->Value;
        }

        bool UpdateItem(short Index , T NewValue)
        {
            Node * Node = GetNode(Index);
            if(Node != NULL)
            {
                Node->Value = NewValue;
                return true;
            }
            else
            {
                return false;
            }
            
        }

        bool InsertAfter(short Index , T NewValue)
        {
            if(Index == 0)
            {
                InsertAtBeginning(NewValue);
                return true;
            }
            else
            {
                Node * Node = GetNode(Index);
                if(Node != NULL)
                {
                    InsertAfter(Node,NewValue);
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
};
