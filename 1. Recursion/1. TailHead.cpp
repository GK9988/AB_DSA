#include <bits/stdc++.h>
using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        cout << n << " "; // Head Recursion
        fun(n - 1);
        cout << n << " "; // Tail Recursion
    }
}

int main()
{
    int x = 3;

    fun(x);
}