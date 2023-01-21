// Finding single missing element in a sorted array
#include <iostream>
using namespace std;

void arrayScanner(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void arrayPrinter(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int formulaMissing(int *arr, int n)
{
    int max = arr[n - 1];

    int seqSum = ((max * (max + 1)) / 2);

    int arrSum = 0;

    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
    }

    return seqSum - arrSum;
}

// used if the starting point is different from 1

int constantSumMissing(int *arr, int n)
{

    int l = arr[0];
    int h = arr[n];

    int diff = arr[0] - 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
        {
            return i + diff;
        }
    }
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];

    arrayScanner(arr, n);

    cout << endl
         << "Array is: ";
    arrayPrinter(arr, n);
    cout << endl;

    cout << "Missing Element Through Formula: " << formulaMissing(arr, n) << endl;
    cout << "Missing Element Through Common Difference: " << constantSumMissing(arr, n);
}