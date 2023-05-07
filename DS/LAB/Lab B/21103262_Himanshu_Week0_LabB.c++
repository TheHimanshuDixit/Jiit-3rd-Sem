#include <bits/stdc++.h>
using namespace std;

//display array numbers
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

//question 1
void average(int *arr, int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
    }
    cout << sum / length;
}


int maxarr(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

// question 3
void freq(int *arr, int length)
{

    int length_freqarray = maxarr(arr, length) + 1;
    int *fre = new int[length_freqarray]{0};

    for (int i = 0; i < length; i++)
    {

        fre[arr[i]]++;
    }
    for (int i = 0; i < length_freqarray; i++)
    {

        if (fre[i] != 0)

            cout << i << " occurs " << fre[i] << " times" << endl;
    }
}

// question 4
void rotate(int *arr, int length)
{
    int *temp = new int(arr[0]);
    for (int i = 1; i < length; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[length - 1] = *temp;
    print(arr, length);
}

// question 5
void secondsmallest1d(int *arr, int n)
{
    for (int i = 0; i < 2; i++)
    {
        int min = arr[i];
        for (int j = i; j < n; j++)
        {
            if (min > arr[j])
            {
                int temp = min;
                min = arr[j];
                arr[j] = temp;
            }
        }
        arr[i] = min;
    }
    cout << arr[1];
}


void secondsmallest2d(int **arr, int r, int c)
{
    int count = 2, min2 = INT_MIN;
    while (count > 0)
    {
        int min1 = INT_MAX;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (min1 >= arr[i][j] && min2 < arr[i][j])
                {
                    min1 = arr[i][j];
                }
            }
        }
        min2 = min1;
        min1 = INT_MAX;
        count--;
    }
    cout << min2;
}


int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    average(arr, n);
    freq(arr, n);
    rotate(arr, n);

    secondsmallest1d(arr, n);
    delete[] arr;

    int row, col;
    cin >> row >> col;
    int **ar = new int *[row];
    for (int i = 0; i < row; i++)
    {
        ar[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> ar[i][j];
        }
    }

    secondsmallest2d(ar, row, col);
    for (int i = 0; i < row; i++) // To delete the inner arrays
        delete[] ar[i];

    delete[] ar;
    return 0;
}
