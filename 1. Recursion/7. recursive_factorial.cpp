// factorial of a number using factorial

#include <bits/stdc++.h>
using namespace std;

int recFact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * recFact(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << n << "! = " << recFact(n);
}