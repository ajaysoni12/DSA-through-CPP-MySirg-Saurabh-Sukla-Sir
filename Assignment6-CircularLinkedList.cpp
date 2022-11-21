#include <bits/stdc++.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class CircularLinkedList
{
private:
    node *last;

public:
    CircularLinkedList();
    void insertAtStart(int);
    void insertAtLast(int);
    void insertNode(node *, int);
    node *searchNode(int);
    void deleteAtStart();
    void deleteAtLast();
    void deleteNode(node *);
    void printList();
    ~CircularLinkedList();
};
CircularLinkedList::~CircularLinkedList()
{
    while (last)
        deleteAtStart();
}
void CircularLinkedList::deleteNode(node *ptr)
{
    if (ptr && last)
    {
        if (last->next == last && last == ptr)
        {
            delete last;
            last = NULL;
        }
        else
        {
            node *t = last->next;
            while (t->next != ptr)
                t = t->next;
            t->next = ptr->next;
            delete ptr;
            if (last == ptr)
                last = t;
        }
    }
    else
        cout << "\nList is empty or invalid address..!!";
}
void CircularLinkedList::deleteAtLast()
{
    if (last)
    {
        node *t = last->next;

        if (t == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            while (t->next != last)
                t = t->next;
            t->next = last->next;
            delete last;
            last = t;
        }
    }
    else
        cout << "\nList is emtpy..!!";
}
void CircularLinkedList::deleteAtStart()
{
    if (last)
    {
        node *t = last->next;
        if (t == last) // last->next = last
            last = NULL;
        else
            last->next = t->next;
        delete t;
    }
    else
        cout << "\nList is emtpy..!!";
}
void CircularLinkedList::insertNode(node *ptr, int data)
{
    if (ptr && last)
    {
        node *n = new node;
        n->item = data;
        n->next = ptr->next;
        ptr->next = n;
        if (ptr == last)
            last = n;
    }
}
node *CircularLinkedList::searchNode(int data)
{
    if (last)
    {
        node *t = last->next;
        do
        {
            if (t->item == data)
                return t;
            t = t->next;
        } while (t != last->next);
    }
    return NULL;
}
void CircularLinkedList::insertAtLast(int data)
{
    node *n = new node;
    n->item = data;
    if (last)
    {
        n->next = last->next;
        last->next = n;
        last = n;
    }
    else
    {
        n->next = n;
        last = n;
    }
}
void CircularLinkedList::printList()
{
    if (last)
    {
        cout << "\nList is: ";
        node *t = last->next;
        do
        {
            cout << t->item << " ";
            t = t->next;
        } while (t != last->next);
    }
    else
        cout << "\nList is empty...!";
}
void CircularLinkedList::insertAtStart(int data)
{
    node *n = new node;
    n->item = data;
    if (last)
    { // When list is not empty
        n->next = last->next;
        last->next = n;
    }
    else
    {
        n->next = n;
        last = n;
    }
}
CircularLinkedList::CircularLinkedList() { last = NULL; }