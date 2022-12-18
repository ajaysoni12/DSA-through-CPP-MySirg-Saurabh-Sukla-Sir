/*
    Assignment 9: Stack Using Array
    Solutions:
*/

#include "Assignment1-ArrayADT.cpp"
using namespace std;
class Stack : private ArrayADT
{
public:
    Stack(int);
    Stack(Stack &);
    void push(int);
    int peek();
    void pop();
    ~Stack();
    virtual bool isFull();
    virtual bool isEmpty();
    int getStackSize();
    void operator=(Stack &);
};

void popFromStack(Stack &s, Stack &minStack)
{
    if (!s.isEmpty())
    {
        s.pop();
        minStack.pop();
    }
    else
        cout << "\nStack is Emtpy";
}

void pushInStack(Stack &s, Stack &minStack, int data)
{
    if (s.isEmpty())
    {
        s.push(data);
        minStack.push(data);
    }
    else if (s.isFull())
        cout << "\nStack OverFlow!";
    else
    {
        s.push(data);
        if (data > minStack.peek())
            minStack.push(minStack.peek());
        else
            minStack.push(data);
    }
}

void Stack::operator=(Stack &s)
{
    ArrayADT::operator=(s);
}

int Stack::getStackSize()
{
    return getCapacity();
}

Stack::Stack(Stack &S) : ArrayADT(S) {}

void reverseStack(Stack &s1)
{
    Stack s2(s1.getStackSize());
    while (!s1.isEmpty())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    s1 = s2; // Assignment Overloading
}

bool Stack::isEmpty()
{
    return ArrayADT::isEmpty();
}

bool Stack::isFull()
{
    return ArrayADT::isFull();
}

Stack::~Stack() {} // called parent called distructor

void Stack::pop()
{
    if (isEmpty())
        cout << "\nStack UnderFlow!";
    else
        delElement(countElement() - 1);
}

int Stack::peek()
{
    if (!isEmpty())
        return getElement(countElement() - 1);
    else
        cout << "\nStack is Emtpy!";
    return -1;
}

void Stack::push(int data)
{
    if (isFull())
        cout << "\nStack OverFlow!";
    else
        appendElement(data);
}

Stack::Stack(int cap) : ArrayADT(cap) {}

int main()
{
    Stack minStack(4);
    Stack s(4);
    pushInStack(s, minStack, 10);
    pushInStack(s, minStack, 20);
    pushInStack(s, minStack, 5);
    pushInStack(s, minStack, 6);
    cout << s.peek() << " " << minStack.peek() << endl;
    popFromStack(s, minStack);
    cout << s.peek() << " " << minStack.peek() << endl;
}