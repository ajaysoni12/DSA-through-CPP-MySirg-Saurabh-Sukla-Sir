/*
    Assignment 2: Problems on Array
    Solutions:
*/


// include Assignment1-ArrayADT.cpp class in our program
#include "Assignment1-ArrayADT.cpp"

class ExtendedArrayADT : public ArrayADT
{
private:
    // private variable or function here
public:
    ExtendedArrayADT(int);
    void sortArray();
    int greatestElement();
    int smallestElement();
    bool searchElement(int);
    void swapElement(int, int);
    int sumOfElement();
    void rotateArray();
    void rotateArrayByOne();
    int secondLargestElement();
    void removeDuplicateElement();
    float averageOfElement();
};

int ExtendedArrayADT::secondLargestElement()
{
    sortArray();
    return getElement(countElement() - 2); // second largest element
}

void ExtendedArrayADT::removeDuplicateElement()
{
    int i, j = 0;
    for (i = 0; i < countElement() - 1; i++)
        if (getElement(i) != getElement(i + 1))
            editElement(j++, getElement(i));
    editElement(j++, getElement(i));
}

void ExtendedArrayADT::rotateArray()
{
    for (int i = countElement() - 1; i > 0; i--)
    {
        int temp = getElement(i);
        editElement(i, getElement(i - 1));
        editElement(i - 1, temp);
    }
}

float ExtendedArrayADT::averageOfElement()
{
    float total = sumOfElement();
    return total / (float)countElement();
}

int ExtendedArrayADT::sumOfElement()
{
    int sum = 0;
    for (int i = 0; i < countElement(); i++)
        sum += getElement(i);
    return sum;
}

bool ExtendedArrayADT::searchElement(int element)
{
    for (int i = 0; i < countElement(); i++)
        if (getElement(i) == element)
            return true;
    return false;
}

int ExtendedArrayADT::greatestElement()
{
    int min = getElement(0);
    for (int i = 1; i < countElement(); i++)
        min = min > getElement(i) ? getElement(i) : min;
    return min;
}

int ExtendedArrayADT::greatestElement()
{
    if (isEmpty())
    {
        cout << "\nArray is empty..!!";
        return -1;
    }
    int max = getElement(0);
    for (int i = 1; i < countElement(); i++)
        max = max < getElement(i) ? getElement(i) : max;
    return max;
}

void ExtendedArrayADT::sortArray()
{
    int i, j;
    for (i = 0; i < countElement(); i++)
        for (j = i + 1; j < countElement(); j++)
            if (getElement(i) > getElement(j))
            {
                int temp = getElement(i);
                editElement(i, getElement(j));
                editElement(j, temp);
            }
}

void ExtendedArrayADT::swapElement(int firstIndex, int secondIndex)
{
    int temp = getElement(firstIndex);
    editElement(firstIndex, getElement(secondIndex));
    editElement(secondIndex, temp);
}

ExtendedArrayADT::ExtendedArrayADT(int cap) : ArrayADT(cap) {}
