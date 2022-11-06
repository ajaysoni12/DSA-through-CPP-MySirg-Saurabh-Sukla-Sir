#include <bits/stdc++.h>
using namespace std;
bool searchElement(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == element)
            return true;
    return false;
}   
int main()
{
    int arr[] = {1, 4, 5, 7, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << searchElement(arr, size, 7);
    return 0;
}