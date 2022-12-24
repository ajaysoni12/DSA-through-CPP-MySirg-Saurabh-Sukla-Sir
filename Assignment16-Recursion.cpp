#include <iostream>
using namespace std;
/* Question 1
Write a recursive function to print first N natural numbers.
*/
void fun1(int n)
{
    if (n)
    {
        fun1(n - 1);
        cout << n << " ";
    }
}

/* Question - 2
Write a recursive function to print first N natural numbers in reverse order
*/
void fun2(int n)
{
    if (n)
    {
        cout << n << " ";
        fun2(n - 1);
    }
}

/* Question - 3
Write a recursive function to print first N odd natural numbres
*/
void fun3(int n)
{
    if (n)
    {
        fun3(n - 1);
        cout << 2 * n - 1 << " ";
    }
}

/* Question - 4
Write a recursive function to print first N odd natural numbres in reverse order
*/
void fun4(int n)
{
    if (n)
    {
        cout << 2 * n - 1 << " ";
        fun4(n - 1);
    }
}
/* Question - 5
Write a recursive function to print first N even natural numbres
*/
void fun5(int n)
{
    if (n)
    {
        fun3(n - 1);
        cout << 2 * n << " ";
    }
}

/* Question - 6
Write a recursive function to print first N even natural numbres in reverse order
*/
void fun6(int n)
{
    if (n)
    {
        cout << 2 * n << " ";
        fun6(n - 1);
    }
}
/* Question 7
Write a recursive function to print squares of first N natural numbers.
*/
void fun7(int n)
{
    if (n)
    {
        fun7(n - 1);
        cout << n * n << " ";
    }
}
/* Question 8
Write a recursive function to print squares of first N natural numbers in reverse order.
*/
void fun8(int n)
{
    if (n)
    {
        cout << n * n << " ";
        fun8(n - 1);
    }
}
/* Question 9
Write a recursive function to print squares of first N natural numbers.
*/
void fun9(int n)
{
    if (n)
    {
        fun9(n - 1);
        cout << n * n * n << " ";
    }
}
/* Question 10
Write a recursive function to print squares of first N natural numbers in reverse order.
*/
void fun10(int n)
{
    if (n)
    {
        cout << n * n * n << " ";
        fun10(n - 1);
    }
}

int main()
{
    // fun1(25);
    // fun2(25);
    // fun3(25);
    // fun4(25);
    // fun5(25);
    // fun6(25);
    // fun7(25);
    // fun8(25);
    // fun9(25);
    // fun10(25);
    return 0;
}