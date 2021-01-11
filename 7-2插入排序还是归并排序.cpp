/*
 * @Author: Whx
 * @Date: 2021-01-07 19:17:31
 * @LastEditTime: 2021-01-07 22:19:26
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;
int a[105], b[105];
int main()
{
    int n;
    cin >> n;
    int i, j;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (i = 0; b[i] <= b[i + 1] && i < n - 1; i++)
        ;
    for (j = i + 1; b[j] == a[j] && j < n; j++)
        ;
    if (j == n)
    {
        cout << "Insertion Sort" << endl;
        sort(a, a + i + 2);
        for (int i = 0; i < n - 1; i++)
        {
            cout << b[i] << " ";
        }
        cout << b[n - 1];
    }
    else
    {
        cout << "Merge Sort" << endl;
        int flag = 1, p = 1;
        while (flag)
        {
            flag = 0;
            for (int i = 0; i < n; i++)
                if (a[i] != b[i])
                    flag = 1;
            p <<= 1;
            for (int i = 0; i < n / p; i++)
                sort(a + i * p, a + (i + 1) * p); //分成p份，每份分别排序
            sort(a + n / p * p, a + n);           //如果不能刚好分成p组，这是最后一份
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << a[i] << " ";
        }
        cout << a[n - 1];
    }
    return 0;
}
