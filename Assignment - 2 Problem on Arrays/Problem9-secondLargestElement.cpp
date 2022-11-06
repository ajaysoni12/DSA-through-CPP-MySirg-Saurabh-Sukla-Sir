#include <iostream>
using namespace std;
void sortArray(int *arr, int arrSize)
{
    int i, j;
    for (i = 0; i < arrSize; i++)
        for (j = i + 1; j < arrSize; j++)
            if (arr[i] > arr[j]) // *(arr+i) > *(arr+j)
                swap(arr[i], arr[j]);
}
int secondLargestElement(int *arr, int size)
{
    sortArray(arr, size);
    return arr[size - 2]; // second largest element
}
int main()
{
    int arr[] = {3, 5, 2, 2, 5, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    cout<<secondLargestElement(arr, arrSize); 
    
    return 0;
}