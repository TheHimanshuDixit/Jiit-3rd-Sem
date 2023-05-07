#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void Solution1()
{
    int n;
    cin >> n;
    int p[n], d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += p[i];
        sum2 += d[i];
    }
    if (sum1 < sum2)
    {
        cout << "There is No Point !!";
        return;
    }
    int ans = 0;
    sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += p[i];
        sum1 -= d[i];
        if (sum1 < 0)
        {
            ans = i;
        }
    }
    cout << ans;
}

void Solution2()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int N, p;
        cin >> N >> p;
        int x[N], y[N], a[N];
        for (int i = 0; i < N; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> y[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        int max = 0;
        for (int i = 0; i < N; i++)
        {
            if (max < ((x[i] * x[i]) + (y[i] * y[i])))
            {
                max = ((x[i] * x[i]) + (y[i] * y[i]));
            }
        }
        int r[max + 1] = {0};
        for (int i = 0; i < N; i++)
        {
            r[((x[i] * x[i]) + (y[i] * y[i]))] += a[i];
            cout << ((x[i] * x[i]) + (y[i] * y[i])) << " " << a[i] << endl;
        }
        int sum = 0;
        for (int i = 0; i < max; i++)
        {
            sum += r[i];
            if (sum >= p)
            {
                float ans = sqrtf(i);
                cout << ans;
                break;
            }
        }
    }
}

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
    {
        string s1 = a.first;
        string s2 = b.first;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 < s2;
    }
    return a.second > b.second;
}

void Solution3()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<pair<string, int>> v;
        for (int i = 0; i < n; i++)
        {
            string s;
            int qnum;
            cin >> s >> qnum;
            v.push_back(make_pair(s, qnum));
        }
        sort(v.begin(), v.end(), cmp);
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << v[i].first << " " << v[i].second << endl;
        }
    }
}

int main()
{
    Solution1();
    Solution2();
    Solution3();
    return 0;
}