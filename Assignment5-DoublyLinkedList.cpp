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
    if (ptr)
    {
        if (ptr->next && ptr->prev)
        {
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
        }
        else if (ptr->prev == NULL)
            deleteAtStart();
        else if (ptr->next == NULL)
            deleteAtLast();
    }
}

void DoublyLinkedList::deleteAtLast()
{
    if (start)
    {
        node *t = start;
        while (t->next != NULL)
            t = t->next;
        if (t->prev)
            t->prev->next = NULL;
        else
            start = NULL;
        delete t;
    }
}

void DoublyLinkedList::deleteAtStart()
{
    if (start)
    {
        node *t = start;
        start = start->next;
        delete t;
        if (start)
            start->prev = NULL;
    }
}

DoublyLinkedList::node *DoublyLinkedList::searchNode(int data)
{
    if (start == NULL)
    {
        cout << "\nList is empty..!!";
        return NULL;
    }
    node *t = start;
    while (t != NULL)
    {
        if (t->item == data)
            return t;
        t = t->next;
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
    if (ptr)
    {
        node *n = new node;
        n->item = data;
        n->next = NULL;
        n->prev = ptr;
        if (ptr->next)
        {
            ptr->next->prev = n;
            n->next = ptr->next;
        }
        ptr->next = n;
    }
}

void DoublyLinkedList::insertAtLast(int data)
{
    node *n = new node;
    n->item = data;
    n->next = NULL;
    n->prev = NULL; // update if start have point atleast one node
    if (start)
    {
        node *t = start;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
        n->prev = t;
    }
}

void DoublyLinkedList::insertAtStart(int data)
{
    node *n = new node;
    n->item = data;
    n->prev = NULL;
    n->next = start;
    if (start)
        start->prev = n;
    start = n;
}

DoublyLinkedList::DoublyLinkedList() { start = NULL; }
