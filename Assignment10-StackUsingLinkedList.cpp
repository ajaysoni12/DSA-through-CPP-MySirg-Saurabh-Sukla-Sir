/*
    Assignment 10: Stack Using Linked List
    Solutions:
*/

#include "Assignment4-SinglyLinkedList.cpp"

class Stack : private SinglyLinkedList
{
private:
public:
    Stack();
    void push(int);
    int peek();
    void pop();
    ~Stack();
    void reverseStack();
    void printList();
    bool isPalinDrome(int);
};

bool Stack::isPalinDrome(int num)
{
    Stack s1;
    int length = 0;
    while (num != 0) // find length
    {
        length++;
        num /= 10;
    }

    for (int i = 1; i <= length / 2; ++i)
    {
        s1.push(num % 10);
        num /= 10;
    }
    if (length % 2)
        num = num / 10; // for odd length
    while (num != 0)
    {
        if (s1.peek() != (num % 10))
            return false;
        s1.pop();
        num /= 10;
    }
    return true;
}

void Stack::reverseStack()
{
    if (start && start->next)
    {
        node *t1, *t2, *t3;
        if (start->next->next == NULL)
        {
            t1 = start->next;
            t1->next = start;
            start->next = NULL;
            start = t1;
        }
        else // for more than two node
        {
            t1 = start;
            t2 = t1->next;
            t3 = t2->next;
            t1->next = NULL;
            do
            {
                t2->next = t1;
                t1 = t2;
                t2 = t3;
                t3 = t3->next;
            } while (t3 != NULL);
            t2->next = t1;
            start = t2;
        }
    }
    /*
    Second Method
    node *t1, *t2;
    if(top && top->next)
    {
        t2 = NULL;
        do
        {
            t1 = top;
            top = top->next;
            t1->next = t2;
            t2 = t1;
        } while(top->next!=NULL);
        top->next = t1;
    }
    */
}

Stack::~Stack() {}

void Stack::pop()
{
    if (isEmpty())
        cout << "\nStack is Empty! ";
    else
        deleteAtBeg();
}

int Stack::peek()
{
    if (start == NULL)
        cout << "\nStack is empty! ";
    else
        return start->item;
    return -1;
}

void Stack::push(int data)
{
    insertAtStart(data);
}

Stack::Stack() : SinglyLinkedList() {}

int main()
{

    Stack obj;
    obj.push(1);
    // obj.pop();
    obj.reverseStack();
    cout << obj.peek();

    return 0;
}