#include <iostream>
using namespace std;

/* MAX-PRIORITY QUEUE(DECENDING ORDER) */
struct node
{
    int item;
    int priorityNo;
    node *next;
};
class maxPriorityQueue
{
private:
    node *start;

public:
    maxPriorityQueue();
    void insert(int, int);
    void del();
    bool isEmpty();
    node *getHPElement();
    int getHPNo();
    ~maxPriorityQueue();
};
maxPriorityQueue::~maxPriorityQueue()
{
    while (start)
        del();
}
int maxPriorityQueue::getHPNo()
{
    if (start)
        return start->priorityNo;
    return -1;
}
node *maxPriorityQueue::getHPElement()
{
    if (start)
        return start;
    return NULL;
}
bool maxPriorityQueue::isEmpty() { return start == NULL; }
void maxPriorityQueue::del()
{
    if (start)
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }
}
void maxPriorityQueue::insert(int data, int pNo)
{
    node *n = new node;
    n->item = data;
    n->priorityNo = pNo;
    if (start == NULL)
    {
        n->next = NULL;
        start = n;
    }
    else
    {
        if (start->priorityNo < n->priorityNo)
        {
            n->next = start;
            start = n;
        }
        else
        {
            node *t = start;
            while (t->next != NULL)
            {
                if (t->next->priorityNo >= n->priorityNo)
                    t = t->next;
                else
                    break;
            }
            n->next = t->next;
            t->next = n;
        }
    }
}
maxPriorityQueue::maxPriorityQueue() { start = NULL; }


/* MIN-PRIORITY QUEUE(ACCENDING ORDER) */

class minPriorityQueue
{
private:
    node *start;

public:
    minPriorityQueue();
    void insert(int, int);
    void del();
    bool isEmpty();
    node *getHPElement();
    int getHPNo();
    ~minPriorityQueue();
};
minPriorityQueue::~minPriorityQueue()
{
    while (start)
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }
}
int minPriorityQueue::getHPNo()
{
    if (start)
    {
        node *tmp = start;
        while (tmp->next)
            tmp = tmp->next;
        return tmp->priorityNo;
    }
    return -1;
}
node *minPriorityQueue::getHPElement()
{
    if (start)
    {
        node *tmp = start;
        while (tmp->next)
            tmp = tmp->next;
        return tmp;
    }
    return NULL;
}
bool minPriorityQueue::isEmpty() { return start == NULL; }
void minPriorityQueue::del()
{
    if (isEmpty())
        cout << "\nPriority Queue UnderFlow!";
    else if (start->next == NULL)
    {
        delete start;
        start = NULL;
    }
    else
    {
        node *t1 = start, *t2 = NULL;
        while (t1->next != NULL)
        {
            t2 = t1;
            t1 = t1->next;
        }
        t2->next = NULL;
        delete t1;
    }
}
void minPriorityQueue::insert(int data, int pNo)
{
    node *n = new node;
    n->item = data;
    n->priorityNo = pNo;
    if (start == NULL)
    {
        n->next = NULL;
        start = n;
    }
    else if (start->next == NULL)
    {
        if (start->priorityNo < pNo) // before
        {
            n->next = start;
            start = n;
        }
        else // After
        {
            start->next = n;
            n->next = NULL;
        }
    }
    else
    {
        node *t1 = start, *t2 = NULL;
        while (t1 != NULL)
        {
            if (t1->priorityNo >= pNo)
                break;
            t2 = t1;
            t1 = t1->next;
        }
        n->next = t2->next;
        t2->next = n;
    }
}
minPriorityQueue::minPriorityQueue() { start = NULL; }
