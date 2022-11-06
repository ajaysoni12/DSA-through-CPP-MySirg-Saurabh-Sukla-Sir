#include <bits/stdc++.h>
using namespace std;
int sumOfElement(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}
int main()
{
    int arr[] = {1, 4, 5, 7, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << sumOfElement(arr, size);
    return 0;
}