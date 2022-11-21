#include <bits/stdc++.h>
using namespace std;
struct node
{
    int item;
    node *next, *prev;
};
class CircularDoublyLinkedList
{
private:
    node *start;

public:
    CircularDoublyLinkedList();
    void insertAtStart(int);
    void insertAtLast(int);
    node *searchNode(int);
    void insertNode(node *, int);
    void deleteAtStart();
    void deleteAtLast();
    void deleteNode(node *);
    void printList();
    ~CircularDoublyLinkedList();
};
CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
    while (start)
        deleteAtStart();
}
void CircularDoublyLinkedList::deleteNode(node *ptr)
{
    if (ptr)
    {
        if (start == start->next)
        {
            delete start;
            start = NULL;
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            if (ptr == start)
                start = start->next;
            delete ptr;
        }
    }
    else
        cout << "\nInvalid address..!!";
}
void CircularDoublyLinkedList::deleteAtLast()
{
    if (start)
    {
        if (start == start->next)
        {
            delete start;
            start = NULL;
        }
        else
        {
            node *temp = start;
            while (temp->next != start)
                temp = temp->next;
            temp->prev->next = temp->next;
            start->prev = temp;
            delete temp;
        }
    }
    else
        cout << "\nList is emtpy..!!";
}
void CircularDoublyLinkedList::deleteAtStart()
{
    if (start)
    {
        node *temp = start;
        if (start == start->next)
            start = NULL;
        else
        {
            start->prev->next = temp->next;
            temp->next->prev = temp->prev;
            start = temp->next;
        }
        delete temp;
    }
    else
        cout << "\nList is emtpy...!!";
}
void CircularDoublyLinkedList::insertNode(node *ptr, int data)
{
    if (ptr)
    {
        node *n = new node;
        n->item = data;
        n->prev = ptr;
        n->next = ptr->next;
        ptr->next = n;
        n->next->prev = n;
    }
    else
        cout << "\nList is emtpy..!!";
}
node *CircularDoublyLinkedList::searchNode(int data)
{
    if (start)
    {
        node *t = start;
        do
        {
            if (t->item == data)
                return t;
            t = t->next;
        } while (t != start);
    }
    else
        cout << "\nList is empty..!!";
    return NULL;
}
void CircularDoublyLinkedList::insertAtLast(int data)
{
    node *n = new node;
    n->item = data;
    if (start)
    {
        n->next = start;
        n->prev = start->prev;
        n->prev->next = n;
        n->next->prev = n;
    }
    else
    {
        n->next = n;
        n->prev = n;
        start = n;
    }
}
void CircularDoublyLinkedList::printList()
{
    if (start)
    {
        node *t = start;
        cout << "\nList is: ";
        do
        {
            cout << t->item << " ";
            t = t->next;
        } while (t != start);
    }
    else
        cout << "\nList is emtpy..!!";
}
void CircularDoublyLinkedList::insertAtStart(int data)
{
    node *n = new node;
    n->item = data;
    if (start)
    {
        n->next = start;
        n->prev = start->prev;
        n->prev->next = n;
        n->next->prev = n;
        start = n;
    }
    else
    {
        n->prev = n;
        n->next = n;
        start = n;
    }
}
CircularDoublyLinkedList::CircularDoublyLinkedList() { start = NULL; }
