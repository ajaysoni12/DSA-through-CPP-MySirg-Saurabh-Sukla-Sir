#include "Assignment11-QueueUsingArray.cpp"
class Deque : public Queue
{
private:
public:
    Deque(int);
    void insertFront(int);
    void deleteRear();
    bool isFull();
    ~Deque();
    /* All Other function is inherited by Queue Class
    Like -
        int getFront();
    int getRear();
    void insertRear(int);
    void deleteFront();
    bool isEmpty();
    int count();
    Queue &operator=(Queue &);
    */
};
void Deque::deleteRear()
{
    if (isEmpty())
        cout << "\nQueue UnderFlow!";
    else if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = capacity - 1;
    else
        rear--;
}
bool Deque::isFull()
{
    return (rear + 1) % capacity == front;
}
void Deque::insertFront(int data)
{
    if (isFull())
        cout << "\nQueue OverFlow!";
    else if (front == -1 && rear == -1) // Queue is Empty
    {
        front = rear = 0;
        ptr[front] = data;
    }
    else if (front == 0)
    {
        front = capacity;
        ptr[--front] = data;
    }
    else
        ptr[--front] = data;
}
Deque::~Deque() {}
Deque::Deque(int cap) : Queue(cap) {}
int main()
{
    Deque d1(5);
    d1.insertFront(10);
    d1.insertFront(20);
    d1.insertRear(40);
    d1.insertFront(30);
    cout << "Front = " << d1.getFront() << " Rear = " << d1.getRear() << endl;
    d1.insertFront(50);
    cout << "Front = " << d1.getFront() << " Rear = " << d1.getRear() << endl;
}
