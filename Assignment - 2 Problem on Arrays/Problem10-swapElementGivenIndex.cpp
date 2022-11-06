#include <iostream>
using namespace std;
void swapElement(int *arr, int size, int firstIndex, int secondIndex)
{
    swap(arr[firstIndex], arr[secondIndex]); 
}
int main()
{
    int arr[] = {4,6,7,3}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    swapElement(arr, size,0,3); 
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" "; 
    return 0;
}