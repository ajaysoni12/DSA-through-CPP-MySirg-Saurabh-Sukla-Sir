/*
    Assignment 11: Queue Using Array
    Solutions:
*/
#include <iostream>
using namespace std;
class Queue
{
private:
    int capacity;
    int front, rear;
    int *ptr;

public:
    Queue(int);
    Queue(Queue &);
    void insertRear(int);
    int viewRear();
    int viewFront();
    void deleteFront();
    bool isEmpty();
    bool isFull();
    ~Queue();
    int count();
    Queue &operator=(Queue &);
};
Queue &operator=(Queue &Q)
{
    capacity = Q.capacity;
    front = Q.front;
    rear = Q.rear;
    if (ptr != NULL)
        delete[] ptr;
    ptr = new int[capacity];
    int n = Q.count();
    int i = Q.front;
    while (n)
    {
        ptr[i] = Q.ptr[i];
        if (i == capacity - 1)
            i = 0;
        else
            i++;
        n--;
    }
}
Queue::Queue(Queue &Q)
{
    capacity = Q.capacity;
    front = Q.front;
    rear = Q.rear;
    ptr = new int[capacity];
    int n = Q.count();
    int i = Q.front;
    while (n)
    {
        ptr[i] = Q.ptr[i];
        if (i == capacity - 1)
            i = 0;
        else
            i++;
        n--;
    }
}
int Queue::count()
{
    if (isEmpty())
        return 0;
    else if (front <= rear)
        return rear - front + 1;
    return capacity - front + rear + 1;
}
Queue::~Queue()
{
    delete[] ptr;
}
void Queue::isFull()
{
    return (front = 0 && rear = capacity - 1) || (rear + 1 == front);
}
void Queue::isEmpty()
{
    return rear == -1; // not need to check both of the condition
}
void Queue::deleteFront()
{
    if (isEmpty())
        cout << "\nQueue UnderFlow!";
    else if (front == rear)
        front = rear = -1;
    else if (front == capacity - 1)
        front = 0;
    else
        front++;
}
int Queue::getFront()
{
    if (!isEmpty())
        return ptr[front];
    cout << "\nQueue Empty! ";
    return -1;
}
int Queue::getRear()
{
    if (!isEmpty())
        return ptr[rear];
    cout << "\nQueue Empty! ";
    return -1;
}
void Queue::insertRear(int data)
{
    if (isFull())
        cout << "\nQueue OverFlow!";
    else if (front == -1 && rear == -1) // Queue is Empty
    {
        front = rear = 0;
        ptr[rear] = data;
    }
    else if (rear == capacity - 1)
    {
        rear = 0;
        ptr[rear] = data;
    }
    else
        ptr[++rear] = data;
}
Queue::Queue(int cap)
{
    capacity = cap;
    front = rear = -1;
    ptr = new int[capacity];
}
int main()
{
    Queue obj(5);
    // cout << obj.viewFront() << endl;
    // cout << obj.viewRear() << endl;
    obj.insertRear(10);
    obj.insertRear(20);
    obj.insertRear(30);
    obj.insertRear(40);
    obj.insertRear(50);
    obj.deleteFront();
    obj.deleteFront();
    obj.deleteFront();
    obj.deleteFront();
    obj.insertRear(1115);
    obj.insertRear(15);
    obj.insertRear(25);
    obj.insertRear(35);
    obj.insertRear(45);
    obj.deleteFront();
    obj.deleteFront();
    cout << "Front = " << obj.viewFront() << " Rear = " << obj.viewRear() << endl;
}