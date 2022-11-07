/* Assignment 3 Solutions
   DynamicArray Data structure
   A
   Link:
*/
#include <iostream>
using namespace std;
class DynamicArrayADT
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    // ArrayADT();
    DynamicArrayADT(int);
    void doubleArray();
    void halfArray();
    int size();
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
    ~DynamicArrayADT();
};

/* return current capacity of dynamic array */
int DynamicArrayADT::size()
{
    return capacity;
}

/* decrease the size of array by half of it's size */
void DynamicArrayADT::halfArray()
{
    capacity = capacity / 2;
    int *temp = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
}

/* increase the size of array by double of it's size */
void DynamicArrayADT::doubleArray()
{
    capacity = 2 * capacity;
    int *temp = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
}

/* pointer point to null via create object
DynamicArrayADT::DynamicArrayADT()
{
    ptr = nullptr;
}
*/

/* create dynamically array, providing capacity */
DynamicArrayADT::DynamicArrayADT(int capacity)
{
    ptr = new int[capacity];   // dynamically created memory
    this->capacity = capacity; // retundancy
    lastIndex = -1;            // becuase it is point to last filled block index
}

/* check array is empty(return true) or not(return false) */
bool DynamicArrayADT::isEmpty()
{
    return lastIndex == -1; // Equal(Empty) or Not Equal(not Empty)
}

/* append the element of lastIndex+1 Position */
void DynamicArrayADT::appendElement(int element)
{
    if (lastIndex == capacity - 1) // Check array is Full
        doubleArray();
    ptr[++lastIndex] = element; // append element
}

/* insert the element of given index */
void DynamicArrayADT::insertElement(int index, int element)
{
    if (index < 0 || index > lastIndex + 1) // check Invalid Index
        cout << "\nInvalid Index...!!";
    else
    {
        if (lastIndex == capacity - 1) // Check array is Full
            doubleArray();
        for (int i = lastIndex; i >= index; i--)
            ptr[i + 1] = ptr[i]; // right shifting by one position
        ptr[index] = element;
        lastIndex++; // update filled block position
    }
}

/* edit an element of given index */
void DynamicArrayADT::editElement(int index, int element)
{
    if (index < 0 || index > lastIndex) // check Invalid Index
        cout << "\nInvalid Index...!!";
    else
        ptr[index] = element;
}

/* delete an element of given index */
void DynamicArrayADT::delElement(int index)
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
        if (lastIndex + 1 == capacity / 2)
            halfArray();
    }
}

/* check array is full(return true) or not(return false) */
bool DynamicArrayADT::isFull()
{
    return lastIndex == capacity - 1; // Full(Equal) or Not(Not Equal)
}

/* get element of given index */
int DynamicArrayADT::getElement(int index)
{
    if (isEmpty())
        cout << "\nArray is empty..";
    else if (index < 0 || index > lastIndex)
        cout << "\nInvalid Index...";
    else
        return ptr[index]; // return value
}

/* count no. of element in array */
int DynamicArrayADT::countElement()
{
    return lastIndex + 1; // return total element
}

/* return index if given element is found or return -1  */
int DynamicArrayADT::searchElement(int element)
{
    for (int i = 0; i <= lastIndex; i++)
        if (ptr[i] == element)
            return i;
    return -1; // valid when array empty
}

/* view all element */
void DynamicArrayADT::viewElements()
{
    cout << endl;
    for (int i = 0; i <= lastIndex; i++)
        cout << ptr[i] << " ";
}

/* DeAllocate dynamically create memory */
DynamicArrayADT::~DynamicArrayADT()
{
    delete[] ptr; // delete dynamically memory
}

// for testing purpose
int main()
{
    DynamicArrayADT obj(2);
    obj.appendElement(1);
    obj.appendElement(2);
    obj.viewElements();
    cout << "\nCapacity: " << obj.size();
    obj.appendElement(3);
    obj.appendElement(4);
    obj.viewElements();
    cout << "\nCapacity: " << obj.size();
    obj.appendElement(5);
    obj.appendElement(6);
    obj.appendElement(7);
    obj.appendElement(8);
    obj.viewElements();
    obj.delElement(0);
    obj.delElement(0);
    obj.delElement(0);
    obj.delElement(0);
    obj.delElement(0);
    obj.delElement(0);
    obj.viewElements();
    cout << "\nCapacity: " << obj.size();

    return 0;
}
