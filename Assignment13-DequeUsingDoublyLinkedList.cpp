#include <iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class Deque
{
private:
    node *front, *rear;

public:
    Deque();
    void insertFront(int);
    void insertRear(int);
    void deleteFront();
    void deleteRear();
    bool isEmpty();
    int getRear();
    int getFront();
    ~Deque();
};
Deque::~Deque()
{
    while (front)
        deleteFront();
}
int Deque::getFront()
{
    if (!isEmpty())
        return front->item;
    cout << "\nQueue Empty!";
    return -1;
}
int Deque::getRear()
{
    if (!isEmpty())
        return rear->item;
    cout << "\nQueue Empty!";
    return -1;
}
bool Deque::isEmpty() { return rear == NULL; }
void Deque::deleteRear()
{
    node *temp = rear;
    if (isEmpty())
        cout << "\nQueue is UnderFlow";
    else if (front == rear)
        front = rear = NULL;
    else
    {
        rear = rear->prev;
        rear->next = NULL;
    }
    delete temp;
}
void Deque::deleteFront()
{
    node *temp;
    if (isEmpty())
        cout << "\nQueue is UnderFlow";
    else if (front == rear)
    {
        delete front;
        front = rear = NULL;
    }
    else
    {
        temp = front;
        front = front->next;
        front->prev = NULL;
        delete temp;
    }
}
void Deque::insertRear(int data)
{
    node *n = new node;
    n->item = data;
    n->prev = rear;
    n->next = NULL;
    if (rear)
        rear->next = n;
    else
        front = n;
    rear = n;
}
void Deque::insertFront(int data)
{
    node *n = new node;
    n->item = data;
    n->prev = NULL;
    n->next = front;
    if (front)
        front->prev = n;
    else
        rear = n;
    front = n;
}
Deque::Deque() { front = rear = NULL; }