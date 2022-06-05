// program to find exponent of a number using recursion
#include <bits/stdc++.h>
using namespace std;

int recExpo(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return m * recExpo(m, n - 1);
}

int fastRecFunc(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        if (n % 2)
        {
            return m * fastRecFunc(m * m, n / 2);
        }
        else
        {
            return fastRecFunc(m * m, n / 2);
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << recExpo(m, n) << endl;     // slower recursion function
    cout << fastRecFunc(m, n) << endl; // faster recursion function
}