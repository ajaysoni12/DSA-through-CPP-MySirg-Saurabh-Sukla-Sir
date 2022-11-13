#include <bits/stdc++.h>
using namespace std;
class DoublyLinkedList
{
private:
    class node
    {
    public:
        int item;
        node *prev, *next;
    };

    node *start;

public:
    DoublyLinkedList();
    void insertAtStart(int);
    void insertAtLast(int);
    void insertNode(node *, int);
    void printList();
    node *searchNode(int);
    void deleteAtStart();
    void deleteAtLast();
    void deleteNode(node *);
    ~DoublyLinkedList();
};

DoublyLinkedList::~DoublyLinkedList()
{
    while (start)
        deleteAtStart();
}

void DoublyLinkedList::deleteNode(node *ptr)
{
    if (ptr == NULL)
        cout << "\nInvalid Address..!!";
    else if (ptr == start)
        deleteAtStart();
    else if (ptr->next == NULL)
    {
        ptr->prev->next = NULL;
        delete ptr;
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
    }
}

void DoublyLinkedList::deleteAtLast()
{
    if (start == NULL)
        cout << "\nList is emtpy..!!";
    else if (start->next == NULL)
    {
        delete start;
        start = NULL;
    }
    else
    {
        node *t = start;
        while (t->next != NULL)
            t = t->next;
        t->prev->next = NULL;
        delete t;
    }
}

void DoublyLinkedList::deleteAtStart()
{
    if (start == NULL)
        cout << "\nList is empty..!!";
    else if (start->next == NULL)
    {
        delete start;
        start = NULL;
    }
    else
    {
        node *t = start;
        start = start->next;
        start->prev = NULL;
        delete t;
    }
}

DoublyLinkedList::node *DoublyLinkedList::searchNode(int data)
{
    if (start == NULL)
        cout << "\nList is empty..!!";
    else
    {
        node *t = start;
        while (t != NULL)
        {
            if (t->item == data)
                return t;
            t = t->next;
        }
    }
    return NULL;
}

void DoublyLinkedList::printList()
{
    if (start == NULL)
        cout << "\nList is emtpy..!!";
    else
    {
        cout << "\nList is: ";
        node *temp = start;
        while (temp)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
    }
}

void DoublyLinkedList::insertNode(node *ptr, int data)
{
    if (ptr == NULL)
    {
        cout << "\nInvalid Address..!!";
        return;
    }
    node *n = new node;
    n->item = data;
    n->prev = ptr;
    if (ptr->next == NULL) // for single node
        n->next = NULL;
    else
    {
        ptr->next->prev = n;
        n->next = ptr->next;
    }
    ptr->next = n;
}

void DoublyLinkedList::insertAtLast(int data)
{
    node *n = new node;
    n->item = data;
    n->next = NULL;

    if (start == NULL)
    {
        start = n;
        n->prev = NULL;
    }
    else
    {
        node *t = start;
        while (t->next != NULL)
            t = t->next;
        n->prev = t;
        t->next = n;
    }
    cout << "inserted..";
}

void DoublyLinkedList::insertAtStart(int data)
{
    node *n = new node;
    n->item = data;
    n->prev = NULL;
    n->next = start;
    if (start == NULL)
        start = n;
    else
    {
        start->prev = n;
        start = n;
    }
}

DoublyLinkedList::DoublyLinkedList() { start = NULL; }
