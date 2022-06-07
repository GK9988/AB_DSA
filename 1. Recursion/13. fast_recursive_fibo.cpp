#include <bits/stdc++.h>
using namespace std;

int F[10];

int fastFibo(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }

    if (F[n - 1] == -1)
        F[n - 1] = fastFibo(n - 1);
    if (F[n - 2] == -1)
        F[n - 2] = fastFibo(n - 2);
    F[n] = F[n - 1] + F[n - 2];
    return F[n];
}

int main()
{
    int n;
    for (int i = 0; i < 10; i++)
    {
        F[i] = -1;
    }

    cin >> n;
    cout << fastFibo(n);
}