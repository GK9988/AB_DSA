// Sum of first n natural numbers;
#include <bits/stdc++.h>
using namespace std;

int recFunc(int n)
{
    if (n > 0)
    {
        return n + recFunc(n - 1);
    }
    return 0;
}

int formFunc(int n)
{
    return ((n * (n + 1)) / (2));
}

int loopFunc(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << recFunc(n) << endl;  // recursive function call
    cout << formFunc(n) << endl; // formula function call
    cout << loopFunc(n) << endl; // loop function call
}