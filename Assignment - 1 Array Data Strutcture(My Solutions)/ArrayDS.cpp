/*
    Assignment - 1

    <-- Array Data Structure -->

    1. Define a class Array to implement array data structure with member variable to store capcity of array,
    last index
        of the last filled box of the array and a pointer to hold the address of the first block of the dynamically created array.l̥
    2. In question 1, define a parameterised constructor to create an array of speficed size.
    3. In question 1, add a method to check whether array is empty or not by returning true or false.
    4. In question 1, define a method to check whether an array is empty or not by returning true or false.
    5. In question 1, define a method to insert a new element in array.
    6. In question 1, define a mehtod to edit an element at specified index.
    7. In question 1, define a mehtod to delete an element at specified index.
    8. In question 1, define a mehtod to check if the array is full by returning true or false.
    9. In question 1, define a mehtod to get element in spefied index.
    10. In question 1, define a mehtod to count number of element present in the array.
    11. In question 1, define a mehtod to deallocated the memory of array.
    12. In question 1, define a mehtod to find an element in the array. Return index if the element found, otherwise return -1.

*/

#include <iostream>
using namespace std;
class Array
{
private:
    int capacity;  // capacity of array
    int lastIndex; // last filled blocked of the array
    int *ptr;      // hold dynamically created array memory

public:
    Array(int capacity)
    {
        ptr = new int[capacity];
        this->capacity = capacity;
        lastIndex = -1;
    }
    bool ifArrayEmpty()
    {
        if (capacity - 1 == lastIndex) // becuase lastIndex point last element so we need to check capacity -1
            return false;              // array is not empty
        return true;                   // array is empty
    }
    void appendElement(int element)
    {
        if (ifArrayEmpty())
        {
            ptr[++lastIndex] = element; // update lastIndex position symultanously
        }
        else
        {
            cout << "\nNot enough space in Array...! ";
            return;
        }
    }
    void insertElement(int element, int index)
    {
        if (ifArrayEmpty())
        {
            if (index <= lastIndex)
            {
                lastIndex++;
                for (int i = index; i <= lastIndex; i++)
                {
                    int temp = ptr[i];
                    ptr[i] = element;
                    element = temp;
                }
            }
            else
            {
                cout << "\nBreak our policy" << endl;
            }
        }
        else
        {
            cout << "\nOutOf bound exception.! " << endl;
            return;
        }
    }
    void editElement(int element, int index)
    {
        if (index <= lastIndex)
        {
            ptr[index] = element;
        }
        else
        {
            cout << "\noutof bound exception!" << endl;
        }
    }
    void deleteElement(int index)
    {
        if (index <= lastIndex)
        {
            for (int i = index; i < lastIndex; i++)
                ptr[i] = ptr[i + 1];
            lastIndex--;
        }
        else
        {
            cout << "\noutof bound exception!" << endl;
        }
    }
    bool ifArrayFull()
    {
        if (lastIndex == capacity - 1)
            return true;
        return false;
    }
    int getElement(int index)
    {
        if (index <= lastIndex)
            return ptr[index];
        else
            cout << "Out of bound exception...!" << endl;
        return -1;
    }
    int countElement()
    {
        return lastIndex + 1;
    }
    ~Array()
    {
        delete ptr; // delete allocated memory
    }
    int findElement(int element)
    {
        for (int i = 0; i <= lastIndex; i++)
            if (ptr[i] == element)
                return i;
        return -1;
    }
    void printAllElement()
    {
        cout << endl;
        for (int i = 0; i <= lastIndex; i++)
            cout << ptr[i] << " ";
        cout << endl;
    }
};
int main()
{
    Array obj(5);
    obj.appendElement(10);
    obj.appendElement(20);
    obj.appendElement(30);
    obj.printAllElement();
    obj.insertElement(15, 1);
    obj.printAllElement();
    obj.appendElement(40);
    obj.printAllElement();
    obj.editElement(5, 0);
    obj.printAllElement();
    obj.deleteElement(2);
    obj.printAllElement();
    cout<<obj.ifArrayFull()<<endl;
    obj.appendElement(50);
    cout<<obj.ifArrayFull()<<endl;
    obj.printAllElement();
    cout<<obj.getElement(1)<<endl;
    cout<<obj.countElement()<<endl;
    cout<<obj.findElement(50);


}
