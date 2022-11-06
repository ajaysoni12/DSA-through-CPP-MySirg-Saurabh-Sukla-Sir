#include <bits/stdc++.h>
using namespace std;
int smallestElement(int arr[], int size)
{
    /* Method 1 */
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
        min = min > arr[i] ? arr[i] : min;
    return min;

    /* Method 2 */
    min = arr[0];
    for (int i = 1; i < size; i++)
        min = min > arr[i] ? arr[i] : min;
    return min;
}
int main()
{
    int arr[] = {1, 4, 5, 7, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << smallestElement(arr, size);
    return 0;
}