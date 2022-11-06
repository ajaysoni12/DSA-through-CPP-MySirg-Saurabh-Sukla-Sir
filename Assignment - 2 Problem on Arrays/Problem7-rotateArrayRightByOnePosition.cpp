#include <iostream>
using namespace std;
void rotateArray(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
        swap(arr[i], arr[i - 1]);
}
int main()
{
    int arr[] = {5, 3, 6, 7, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before rotate\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    rotateArray(arr, size);
    cout << "\nAfter rotate\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}