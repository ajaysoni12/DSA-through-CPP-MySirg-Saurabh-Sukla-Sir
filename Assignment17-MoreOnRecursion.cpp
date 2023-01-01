#include <iostream>
using namespace std;
/* Question -1
Write a recursive function to calaculate sum of first N natural numbers.
*/
int fun1(int n)
{
    if (n)
        return n + fun1(n - 1);
}

/* Question -1
Write a recursive function to calaculate sum of first N natural numbers.
*/
int fun2(int n)
{
    if (n)
        return (2 * n - 1) + fun2(n - 1);
}
/* Question -1
Write a recursive function to calaculate sum of first N natural numbers.
*/
int fun3(int n)
{
    if (n)
        return (2 * n) + fun3(n - 1);
}
/* Question -1
Write a recursive function to calaculate sum of first N natural numbers.
*/
int fun4(int n)
{
    if (n)
        return (n * n) + fun4(n - 1);
}
int fun5(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * fun5(n - 1);
}
int fun6(int n)
{
    if (n)
        return fun6(n / 10) + n % 10;
}
void fun7(int n)
{
    if (n)
    {
        fun7(n / 2);
        cout << n % 2;
    }
}
int fun8(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
        return fun8(n - 2) + fun8(n - 1);
}
int fun9(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            return fun9(a - b, b);
        }
        else
        {
            return fun9(a, b - a);
        }
    }
    return a;
}
double fun10(double base, int expo)
{
    /* Base condition */
    if(expo == 0)
        return 1;
    else if(expo > 0)
        return base * fun10(base, expo - 1);
    else
        return 1 / fun10(base, -expo);
}
int main()
{
    cout << fun10(2,5);
}