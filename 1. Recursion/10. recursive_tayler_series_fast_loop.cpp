#include <bits/stdc++.h>
using namespace std;

double e(int x, int n)
{
    double s = 1;
    for (; n > 0; n--)
    {
        s = 1 + (x * s) / n;
    }
    return s;
}

int main()
{
    int x;
    int n;
    cin >> x >> n;
    cout << e(x, n);
}