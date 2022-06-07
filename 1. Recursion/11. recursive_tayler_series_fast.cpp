#include <bits/stdc++.h>
using namespace std;

double e(int x, int n)
{
    static double s = 1;
    if (n == 0)
    {
        return s;
    }

    s = 1 + (x * s) / n;

    return e(x, n - 1);
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << e(x, n);
}