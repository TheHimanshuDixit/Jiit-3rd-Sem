#include <iostream>
using namespace std;

void Question1(int arr[], int n)
{
    int total = n * (n + 1) / 2;
    int f[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        f[arr[i]]++;
    }
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (f[i] == 0)
        {
            a1 = i;
        }
        if (f[i] == 2)
        {
            a2 = i;
        }
    }
    cout << a1 << " " << a2;
}
void Question2(int arr[], int n, int x)
{
    int ans = -1, ans2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= x)
        {
            ans = arr[i];
        }
        if (arr[i] >= x)
        {
            ans2 = arr[i];
        }
    }
    if (ans != -1)
    {
        cout << ans;
    }
    else
    {
        cout << "floor dosen't exist in array";
    }
    cout << endl;
    if (ans2 != -1)
    {
        cout << ans2;
    }
    else
    {
        cout << "Ceil dosen't exist in array";
    }
    // method 2 Binary Search
    /*int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (l == r)
        {
            if (arr[mid] == x)
            {
                cout << "Floor = " << x << " Ceil = " << x;               
            }
            else if (arr[mid] < x)
            {
                cout << "Floor = " << arr[mid];
                if (mid + 1 > n - 1)
                {
                    cout << "Ceil dosen't exist in array";
                }
                else
                {
                    cout << " Ceil = " << arr[mid + 1];
                }
            }
            else
            {
                cout << "Ceil = " << arr[mid];
                if (mid - 1 < 0)
                {
                    cout << "Floor dosen't exist in array";
                }
                else
                {
                    cout << " Floor = " << arr[mid - 1];
                }
            }
        }
        else if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }*/
}
void Question3(int arr[], int n, int diff)
{
    int l = 0, r = n - 1, mid, flag = 0;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i] + diff;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == x)
            {
                cout << arr[i] << " " << arr[j] << endl;
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        cout << "Pair does not exist";
    }
}
int main()
{
    int n, x, diff;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Question1(arr, n);
    cin >> x;
    Question2(arr, n, x);
    cin >> diff;
    Question3(arr, n, diff);

    return 0;
}