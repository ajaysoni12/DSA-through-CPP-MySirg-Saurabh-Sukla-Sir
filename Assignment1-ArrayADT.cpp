/*
    Assignment 1: Array Data Structure
    Solutions:
*/

#include <bits/stdc++.h>
using namespace std;
class ArrayADT
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    ArrayADT(int);
    bool isEmpty();
    void appendElement(int);
    void insertElement(int, int);
    void editElement(int, int);
    void delElement(int);
    bool isFull();
    int getElement(int);
    int countElement();
    int searchElement(int);
    void viewElements();
    ~ArrayADT();
};

/* create dynamically array, providing capacity */
ArrayADT::ArrayADT(int capacity)
{
    ptr = new int[capacity];   // dynamically created memory
    this->capacity = capacity; // retundancy
    lastIndex = -1;            // becuase it is point to last filled block index
}

/* check array is empty(return true) or not(return false) */
bool ArrayADT::isEmpty()
{
    return lastIndex == -1; // Equal(Empty) or Not Equal(not Empty)
}

/* append the element of lastIndex+1 Position */
void ArrayADT::appendElement(int element)
{
    if (lastIndex == capacity - 1) // Check array is Full
        cout << "\nArray is already Full...!!";
    else
        ptr[++lastIndex] = element; // append element
}

/* insert the element of given index */
void ArrayADT::insertElement(int index, int element)
{
    if (lastIndex == capacity - 1) // Check array is Full
        cout << "\nOverFlow..!!";
    else if (index < 0 || index > lastIndex + 1) // check Invalid Index
        cout << "\nInvalid Index...!!";
    else
    {
        for (int i = lastIndex; i >= index; i--)
            ptr[i + 1] = ptr[i]; // right shifting by one position
        ptr[index] = element;
        lastIndex++; // update filled block position
    }
}

/* edit an element of given index */
void ArrayADT::editElement(int index, int element)
{
    if (index < 0 || index > lastIndex) // check Invalid Index
        cout << "\nInvalid Index...!!";
    else
        ptr[index] = element;
}

/* delete an element of given index */
void ArrayADT::delElement(int index)
{
    if (lastIndex == -1) // Check Array is Empty?
        cout << "\nUnderFlow...!!";
    else if (index < 0 || index > lastIndex) // check invalid index
        cout << "\nInvalid Index..!!";
    else
    {
        for (int i = index; i < lastIndex; i++) // left shifting
            ptr[i] = ptr[i + 1];
        lastIndex--;
    }
}

/* check array is full(return true) or not(return false) */
bool ArrayADT::isFull()
{
    return lastIndex == capacity - 1; // Full(Equal) or Not(Not Equal)
}

/* get element of given index */
int ArrayADT::getElement(int index)
{
    if (isEmpty())
        cout << "\nArray is empty..";
    else if (index < 0 || index > lastIndex)
        cout << "\nInvalid Index...";
    else
        return ptr[index]; // return value
}

/* count no. of element in array */
int ArrayADT::countElement()
{
    return lastIndex + 1; // return total element
}

/* return index if given element is found or return -1  */
int ArrayADT::searchElement(int element)
{
    for (int i = 0; i <= lastIndex; i++)
        if (ptr[i] == element)
            return i;
    return -1; // valid when array empty
}

/* view all element */
void ArrayADT::viewElements()
{
    cout << endl;
    for (int i = 0; i <= lastIndex; i++)
        cout << ptr[i] << " ";
}

/* DeAllocate dynamically create memory */
ArrayADT::~ArrayADT()
{
    delete[] ptr; // delete dynamically memory
}

