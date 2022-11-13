#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedList
{
private:
    class node
    {
    public:
        int item;
        node *next;
    };

    node *start;

public:
    SinglyLinkedList();
    void insertAtStart(int);
    void insertAtEnd(int);
    void insertAtAfter(node *, int);
    node *searchNode(int);
    void deleteAtBeg();
    void deleteAtLast();
    void printList();
    void deleteNode(node *);
    ~SinglyLinkedList();
};

void SinglyLinkedList::printList()
{
    if (start == NULL)
        cout << "\nList is emtpy..!!";
    else
    {
        cout << "\nList is: ";
        node *temp = start;
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
    }
}

SinglyLinkedList::~SinglyLinkedList()
{
    while (start)
        deleteAtBeg();
}

void SinglyLinkedList::deleteNode(node *ptr)
{
    if (start == NULL)
        cout << "\nList is empty..!!";
    else
    {
        node *temp = start;
        while (temp->next != ptr)
            temp = temp->next;
        temp->next = ptr->next;
        delete ptr;
    }
}

void SinglyLinkedList::deleteAtLast()
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
        node *temp = start;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
}

void SinglyLinkedList::deleteAtBeg()
{
    if (start == NULL)
        cout << "\nList is empty..!!";
    else
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }
}

void SinglyLinkedList::insertAtAfter(node *ptr, int data)
{
    node *temp = new node;
    temp->item = data;
    ptr->next = temp->next;
    ptr->next = temp;
}

SinglyLinkedList::node *SinglyLinkedList::searchNode(int item)
{
    node *temp = start;
    while (temp != NULL)
        if (temp->item == item)
            return temp;
    return NULL; // also valid for empty string
}

void SinglyLinkedList::insertAtEnd(int data)
{
    node *temp = new node;
    temp->item = data;
    temp->next = NULL;

    if (start == NULL)
        start = temp;
    else
    {
        node *n = start;
        while (n != NULL)
            n = n->next;
        n = temp;
    }
}

void SinglyLinkedList::insertAtStart(int data)
{
    node *temp = new node;
    temp->item = data;
    temp->next = start;
    start = temp;
}

SinglyLinkedList::SinglyLinkedList() { start = NULL; }