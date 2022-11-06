#include <iostream>
using namespace std;
int removeDuplicate(int *arr, int size)
{
    int i, j = 0;
    for (i = 0; i < size - 1; i++)
        if (arr[i] != arr[i + 1])
            arr[j++] = arr[i];
    arr[j++] = arr[i];
}
int main()
{
    int arr[] = {4, 6, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int length = removeDuplicate(arr, size);
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    return 0;
}