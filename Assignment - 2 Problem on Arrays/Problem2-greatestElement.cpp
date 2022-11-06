#include <bits/stdc++.h>
using namespace std;
int greatestElement(int arr[], int size)
{
    /* Method 1 */
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
        max = max < arr[i] ? arr[i] : max;
    return max;

    /* Method 2 */
    max = arr[0];
    for (int i = 1; i < size; i++)
        max = max < arr[i] ? arr[i] : max;
    return max;
}
int main()
{
    int arr[] = {1, 4, 5, 7, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << greatestElement(arr, size);
    return 0;
}