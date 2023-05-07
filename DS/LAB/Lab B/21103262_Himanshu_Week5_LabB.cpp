#include <bits/stdc++.h>
using namespace std;
void permute(string a, int l, int r, string arr[], int *n)
{
    if (l == r)
    {
        arr[*n] = a;
        *n = *n + 1;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l + 1, r, arr, n);
            swap(a[l], a[i]);
        }
    }
}

void Sort(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int invCount(int arr[], int n)
{
    int i;
    int c = n - 1;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            break;
        }
        c--;
    }
    if (i == 0)
        return c + 1;
    else
        return c;
}

void Sort(int arr1[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }
}

int minSwaps(int arr[], int n)
{
    int i;
    int c = n - 1;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            break;
        }
        c--;
    }
    if (i == 0)
        return c + 1;
    else
        return c;
}

void q1()
{
    string str = "ABC";
    int n = str.size();
    int x = 1;
    for (int i = 1; i <= n; i++)
    {
        x = x * i;
    }
    string arr[x];
    int *temp = new int;
    *temp = 0;
    permute(str, 0, n - 1, arr, temp);
    delete temp;
    Sort(arr, x);
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << endl;
    }
}

void q2()
{
    int n, temp;
    cout << "Enter the number of elements : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> temp;
        arr[i] = temp;
    }
    cout << "The inversion count of the array is : " << invCount(arr, n);
}

void q3()
{
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    int arr[n], temp;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> temp;
        arr[i] = temp;
    }
    int k;
    cout << "Enter the value of k : ";
    cin >> k;
    if (k < 1 && k > n)
    {
        cout << "Element does not exist!!\n";
    }
    else
    {
        Sort(arr, n);
        cout << "kth Smallest element is : " << arr[k - 1];
    }
}

void q4()
{
    int n, temp;
    cout << "Enter the number of elements : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> temp;
        arr[i] = temp;
    }
    cout << "Minimum no. of swaps to sort the array : " << minSwaps(arr, n);
}

int main()
{
    int ch;
    cout << "##########################Week 5 LAB B##########################################\n";
st:
    cout << "\n\n";
    cout << "1. Print all unique permutations of the given string in lexicographically sorted order.\n";
    cout << "2. TO Inversion Count in the array.\n";
    cout << "3. To find the Kth smallest element in the given array.\n";
    cout << "4. To find minimum number of swaps required to sort the array in strictly increasing order. \n";
    cout << "5. Quit\n";
    cout << "Enter your choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        q1();
        goto st;
    case 2:
        q2();
        goto st;
    case 3:
        q3();
        goto st;
    case 4:
        q4();
        goto st;
    case 5:
        cout << "Thanks to join\n";
        return 0;
    default:
        cout << "Invalid input!!\n";
        goto st;
    }
}
