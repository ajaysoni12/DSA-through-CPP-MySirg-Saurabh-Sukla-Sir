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
int main()
{
    int arr[] = {3, 5, 2, 2, 5, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    sortArray(arr, arrSize);
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    return 0;
}