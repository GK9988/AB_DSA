// static and global variables have same effect on the output as only one copy is supplied to the whole program
#include <bits/stdc++.h>
using namespace std;

// int x = 0; // global variable
int fun(int n)
{
    if (n > 0)
    {
        static int x = 0; // static variable
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    cout << fun(n);
}