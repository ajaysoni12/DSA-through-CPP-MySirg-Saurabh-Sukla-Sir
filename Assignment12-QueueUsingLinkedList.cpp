#include <iostream>
using namespace std;
struct node
{
public:
    int item;
    node *next;
};
class Queue
{
private:
    node *front, *rear;

public:
    Queue();
    void insertRear(int);
    int getRear();
    int getFront();
    bool isEmpty();
    void deleteFront();
    ~Queue();
    int countElement();
    void sortQueue();
    void sortQueueDecending();
};
void Queue::sortQueueDecending()
{
    /* With Queue Operation */
    Queue q2, q3;

    while (front != NULL)
    {
        if (q2.isEmpty())
            q2.insertRear(getFront());
        else
        {
            if (getFront() <= q2.getRear())
                q2.insertRear(getFront());
            else
            {
                node *temp = q2.front;
                int flag = 0;
                while (temp)
                {
                    if (getFront() > temp->item && flag == 0)
                    {
                        q3.insertRear(getFront());
                        flag = 1;
                        break;
                    }
                    else
                        q3.insertRear(temp->item);
                    temp = temp->next;
                }
                if (flag == 0)
                    q3.insertRear(getFront());
                while (q2.front)
                {
                    q3.insertRear(q2.getFront());
                    q2.deleteFront();
                }
                while (q3.front)
                {
                    q2.insertRear(q3.getFront());
                    q3.deleteFront();
                }
            }
        }
        deleteFront();
    }
    while (q2.front)
    {
        insertRear(q2.getFront());
        q2.deleteFront();
    }

    /* Without Queue Operation  */
    if (front != rear)
    {
        node *t1 = front, *t2;
        while (t1 != NULL)
        {
            t2 = t1;
            while (t2 != NULL)
            {
                if (t2->item > t1->item)
                {
                    int temp = t2->item;
                    t2->item = t1->item;
                    t1->item = temp;
                }
                t2 = t2->next;
            }
            t1 = t1->next;
        }
    }
}
void Queue::sortQueue()
{
    /* With Queue Operation */
    Queue q2, q3;

    while (front != NULL)
    {
        if (q2.isEmpty())
            q2.insertRear(getFront());
        else
        {
            if (getFront() >= q2.getRear())
                q2.insertRear(getFront());
            else
            {
                node *temp = q2.front;
                int flag = 0;
                while (temp)
                {
                    if (getFront() < temp->item && flag == 0)
                    {
                        q3.insertRear(getFront());
                        flag = 1;
                        break;
                    }
                    else
                        q3.insertRear(temp->item);
                    temp = temp->next;
                }
                if (flag == 0)
                    q3.insertRear(getFront());
                while (q2.front)
                {
                    q3.insertRear(q2.getFront());
                    q2.deleteFront();
                }
                while (q3.front)
                {
                    q2.insertRear(q3.getFront());
                    q3.deleteFront();
                }
            }
        }
        deleteFront();
    }
    while (q2.front)
    {
        insertRear(q2.getFront());
        q2.deleteFront();
    }

    /* Without Queue Operation
    if (front != rear)
    {
        node *t1 = front, *t2;
        while (t1 != NULL)
        {
            t2 = t1;
            while (t2 != NULL)
            {
                if (t2->item < t1->item)
                {
                    int temp = t2->item;
                    t2->item = t1->item;
                    t1->item = temp;
                }
                t2 = t2->next;
            }
            t1 = t1->next;
        }
    }
    */
}
int Queue::countElement()
{
    int count = 0;
    node *temp = front;
    while (temp)
    {
        count++;
        temp = temp->next;
    };
    return count;
}
Queue::~Queue()
{
    while (front)
        deleteFront();
}
void Queue::deleteFront()
{
    if (!isEmpty())
    {
        node *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }
    else
        cout << "\nQueue is Empty! ";
}
bool Queue::isEmpty()
{
    return front == NULL; // not need to check for rear
}
int Queue::getFront()
{
    if (!isEmpty())
        return front->item;
    cout << "\nQueue Empty!";
    return -1;
}
int Queue::getRear()
{
    if (!isEmpty())
        return rear->item;
    cout << "\nQueue Empty!";
    return -1;
}
void Queue::insertRear(int data)
{
    node *temp = new node;
    temp->item = data;
    temp->next = NULL;
    if (rear == NULL) // node need to check front = NULL;
        front = temp;
    else
        rear->next = temp;
    rear = temp;
}
Queue::Queue()
{
    front = rear = NULL;
}
int main()
{
    Queue q;
    q.insertRear(20);
    q.insertRear(10);
    q.insertRear(50);
    q.insertRear(30);
    cout << "Front = " << q.getFront() << endl;
    cout << "Rear = " << q.getRear() << endl;
    q.sortQueueDecending();
    cout << "Front = " << q.getFront() << endl;
    cout << "Rear = " << q.getRear() << endl;
    return 0;
}