#include <bits/stdc++.h>
using namespace std;

void Solution1(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == i + 1)
        {
            cout << i + 1 << " ";
        }
    }
}

int sum(int arr[], int from, int to)
{
    int total = 0;
    for (int i = from; i <= to; i++)
        total += arr[i];
    return total;
}

int Solution2(int arr[], int size, int k)
{
    if (k == 1)
        return sum(arr, 0, size - 1);
    if (size == 1)
        return arr[0];

    int best = INT_MAX;
    for (int i = 1; i <= size; i++)
        best = min(best, max(Solution2(arr, i, k - 1), sum(arr, i, size - 1)));
    return best;
}

void Solution3(int arr[], int n, int lowVal, int highVal)
{
    int start = 0, end = n - 1;
    for (int i = 0; i <= end;)
    {
        if (arr[i] < lowVal)
        {
            if (i == start)
            {
                start++;
                i++;
            }
            else
                swap(arr[i++], arr[start++]);
        }

        else if (arr[i] > highVal)
            swap(arr[i], arr[end--]);

        else
            i++;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Solution 1 : \n";
    Solution1(arr, n);
    int k;
    cin >> k;
    cout << "Solution 2 : \n";
    cout << Solution2(arr, n, k);
    int a, b;
    cin >> a >> b;
    cout << "Solution 3 : \n";
    Solution3(arr, n, a, b);
    return 0;
}