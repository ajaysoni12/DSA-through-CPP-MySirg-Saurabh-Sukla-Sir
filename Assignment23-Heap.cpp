#include <iostream>
using namespace std;
#define EMPTY_HEAP -2
class Heap
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Heap(int);
    Heap(Heap &);
    bool isEmpty();
    void insert(int);
    void edit(int, int);
    int del();
    bool isFull();
    int get(int);
    int count();
    int find(int);
    void doubleArray();
    void halfArray();
    int size();
    int max();
    ~Heap();
    Heap &operator=(Heap &);
};

Heap &Heap::operator=(Heap &h)
{
    capacity = h.capacity;
    lastIndex = h.lastIndex;
    if (ptr != NULL)
        delete[] ptr;
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
        ptr[i] = h.ptr[i];
    return *this;
}

Heap::Heap(Heap &h)
{
    capacity = h.capacity;
    lastIndex = h.lastIndex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
        ptr[i] = h.ptr[i];
}

int Heap::max()
{
    if (!isEmpty())
        return ptr[0];
    else
        throw EMPTY_HEAP;
}

int Heap::del()
{
    int i, item, temp, index, leftIndex, rightIndex;
    if (isEmpty())
        throw EMPTY_HEAP;
    else
    {
        item = ptr[0];
        temp = ptr[lastIndex];
        lastIndex--;
        index = 0;
        leftIndex = 1;
        rightIndex = 2;
        while (leftIndex < lastIndex)
        {

            if (ptr[leftIndex] > ptr[rightIndex])
            {
                if (temp < ptr[leftIndex])
                {
                    ptr[index] = ptr[leftIndex];
                    index = leftIndex;
                }
                else
                    break;
            }
            else
            {
                if (temp < ptr[rightIndex])
                {
                    ptr[index] = ptr[rightIndex];
                    index = rightIndex;
                }
                else
                    break;
            }
            leftIndex = 2 * index + 1;
            rightIndex = 2 * index + 2;
        }
        if (leftIndex == lastIndex && temp < ptr[leftIndex])
        {
            ptr[index] = ptr[leftIndex];
            index = leftIndex;
        }

        ptr[index] = temp;

        if (capacity / 2 >= lastIndex + 1 && capacity > 1)
            halfArray();
        return item;
    }
}

void Heap::insert(int data)
{
    int i, index, parIndex;
    if (isFull())
        doubleArray();
    for (index = lastIndex + 1; index > 0; index = parIndex)
    {
        parIndex = (index - 1) / 2;
        if (ptr[parIndex] < data)
            ptr[index] = ptr[parIndex];
        else
            break;
    }
    ptr[index] = data;
    lastIndex++;
}

int Heap::size()
{
    return capacity;
}

void Heap::halfArray()
{
    int *temp = new int[capacity / 2];
    for (int i = 0; i <= lastIndex; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
    capacity /= 2;
}

void Heap::doubleArray()
{
    int *temp = new int[capacity * 2];
    for (int i = 0; i <= lastIndex; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
    capacity *= 2;
}

Heap::Heap(int cap)
{
    capacity = cap;
    lastIndex = -1;
    ptr = new int[capacity];
}

bool Heap::isEmpty()
{
    return lastIndex == -1;
}

void Heap::edit(int index, int data)
{
    if (index >= 0 && index <= lastIndex)
        ptr[index] = data;
}

bool Heap::isFull()
{
    return lastIndex == capacity - 1;
}

int Heap::get(int index)
{
    if (index >= 0 && index <= lastIndex)
        return ptr[index];
    cout << endl
         << "Invalid index or empty array";
    return -1;
}

int Heap::count()
{
    return lastIndex;
}

Heap::~Heap()
{
    delete[] ptr;
}

int Heap::find(int data)
{
    int i;
    for (i = 0; i <= lastIndex; i++)
        if (ptr[i] == data)
            return i;
    return -1;
}

void heap_sort(int A[], int N)
{
    Heap obj(N);
    for (int i = 0; i < N; i++)
        obj.insert(A[i]);
    for (int i = N - 1; i >= 0; i--)
        A[i] = obj.del();
}
int main()
{
    int A[] = {77, 43, 90, 81, 21, 35, 16, 50, 18, 70};
    heap_sort(A, 10);
    cout << endl;
    for (int i = 0; i <= 9; i++)
        cout << " " << A[i];
    cout << endl;
    return 0;
}