// finding e^x by tayler series terms by using recursion
#include <bits/stdc++.h>
using namespace std;

double e(int x, int n)
{
    static double p = 1;
    static double f = 1;
    double result;

    if (n == 0)
    {
        return 1;
    }

    result = e(x, n - 1);
    p *= x;
    f *= n;
    return result + (p / f);
}

int main()
{
    int x;
    int n;
    cin >> x >> n;
    cout << e(x, n);
}