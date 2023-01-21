#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

class Array
{
public:
    int *arr;
    int size;
    int length;

    void sizeInit(int sizeInput)
    {
        size = sizeInput;
        arr = new int[size];
    }

    void init()
    {
        cout << endl
             << "Enter the size of the array: ";
        cin >> size;
        cout << endl;

        arr = new int[size];
    }

    void dataInit()
    {
        cout << "Enter the number of elements you want to add: ";
        cin >> length;
        cout << endl;

        for (int i = 0; i < length; i++)
        {
            cin >> arr[i];
        }
    }

    void display()
    {
        cout << endl
             << "Array: ";
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void append(int x)
    {
        if (size > length)
        {
            arr[length] = x;
            length++;
        }
    }

    void insert(int index, int x)
    {
        if (index >= 0 && index <= length)
            for (int i = length; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }

        arr[index] = x;
        length++;
    }

    int deleteElem(int index)
    {
        if (index >= 0 && index < length)
        {
            int x = arr[index];
            for (int i = index; i < length - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            length--;
            return x;
        }
        return 0;
    }

    int linearSearch(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == key)
                return i;
        }
        return -1;
    }

    int improvedLinearSearch1(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == key)
            {
                swap(arr[i], arr[i - 1]);
                return i;
            }
        }
        return -1;
    }
    int improvedLinearSearch2(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == key)
            {
                swap(arr[i], arr[0]);
                return i;
            }
        }
        return -1;
    }

    int normalBinarySearch(int key, int low, int high)
    {

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (key == arr[mid])
                return mid;
            else if (key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    int recursiveBinarySearch(int key, int low, int high)
    {
        int mid;
        if (low > high)
        {
            return -1;
        }
        mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            return recursiveBinarySearch(key, low, mid - 1);
        else
            return recursiveBinarySearch(key, mid + 1, high);
    }

    int get(int index)
    {
        if (index < length && index >= 0)
        {
            return arr[index];
        }
        return -1;
    }

    void set(int index, int value)
    {
        if (index < length && index >= 0)
        {
            arr[index] = value;
        }
    }

    int max()
    {
        int maxValue = arr[0];
        for (int i = 0; i < length; i++)
        {
            if (arr[i] > maxValue)
                maxValue = arr[i];
        }
        return maxValue;
    }

    int min()
    {
        int minValue = arr[0];
        for (int i = 0; i < length; i++)
        {
            if (arr[i] < minValue)
                minValue = arr[i];
        }
        return minValue;
    }

    int sum()
    {
        int sumValue = 0;
        for (int i = 0; i < length; i++)
        {
            sumValue += arr[i];
        }
        return sumValue;
    }

    float average()
    {
        float sumValue = 0;
        for (int i = 0; i < length; i++)
        {
            sumValue += arr[i];
        }
        return sumValue / length;
    }

    void reverse1()
    {
        int *newArr;
        newArr = new int[length];

        for (int i = length - 1, j = 0; i >= 0; i--, j++)
        {
            newArr[j] = arr[i];
        }
        arr = newArr;
    }

    void reverse2()
    {
        for (int i = 0, j = length - 1; i < j; i++, j--)
        {
            swap(arr[i], arr[j]);
        }
    }

    void sortedInsert(int x)
    {
        int i = length - 1;
        while (arr[i] > x)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = x;
        length++;
    }

    int checkSort()
    {
        for (int i = 0; i < length - 2; i++)
        {
            if (arr[i] > arr[i + 1])
                return 0;
        }
        return 1;
    }

    void negativeDisplacement()
    {
        int i = 0;
        int j = length - 1;

        while (i < j)
        {
            while (arr[i] < 0)
            {
                i++;
            }
            while (arr[j] >= 0)
            {
                j--;
            }
            if (i < j)
                swap(arr[i], arr[j]);
        }
    }

    void merge(Array arr1, Array arr2)
    {
        int i, j, k;
        i = j = k = 0;
        size = arr1.size + arr2.size;

        while (i < arr1.length && j < arr2.length)
        {
            if (arr1.arr[i] < arr2.arr[j])
            {
                arr[k++] = arr1.arr[i++];
            }
            else
            {
                arr[k++] = arr2.arr[j++];
            }
        }

        for (; i < arr1.length; i++)
        {
            arr[k++] = arr1.arr[i];
        }
        for (; j < arr2.length; j++)
        {
            arr[k++] = arr2.arr[j];
        }
        length = arr1.length + arr2.length;
    }

    void unsortedUnion(Array arr1, Array arr2)
    {
        length = 0;
        size = arr1.size + arr2.size;

        for (int i = 0; i < arr1.length; i++)
        {
            arr[i] = arr1.arr[i];
            length++;
        }

        for (int i = 0; i < arr2.length; i++)
        {
            int flag = 0;
            for (int j = 0; j < length; j++)
            {
                if (arr2.arr[i] == arr[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                continue;
            }
            else
            {
                arr[length++] = arr2.arr[i];
            }
        }
    }

    void sortedUnion(Array arr1, Array arr2)
    {
    }
};

int main()
{
    Array arr1, arr2, arr3;
    arr1.init();
    arr2.init();

    cout << "Enter data for array 1" << endl;
    arr1.dataInit();

    cout << "Enter data for array 2" << endl;
    arr2.dataInit();

    cout << "Array 1: ";
    arr1.display();

    cout << "Array 2: ";
    arr2.display();

    cout << "Union Array: ";
    arr3.unsortedUnion(arr1, arr2);
    arr3.display();
}