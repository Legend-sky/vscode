/*
 * @Author: Whx
 * @Date: 2021-01-09 21:01:23
 * @LastEditTime: 2021-01-09 21:29:39
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

void PercDown(int a[], int p, int n) //最小堆
{
    int parent, child;
    int x;
    x = a[p];
    for (parent = p; (parent * 2 + 1) < n; parent = child)
    {
        child = parent * 2 + 1; //左孩子
        if ((child != n - 1) && (a[child] > a[child + 1]))
        {
            child++;
        }
        if (x <= a[child])
        {
            break;
        }
        else
        {
            a[parent] = a[child];
        }
    }
    a[parent] = x;
}
void HeapSort(int a[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        PercDown(a, 0, i);
    }
}
int main()
{
    int n, m, i, tmp;
    int a[10];
    cin >> n >> m;
    if (n < m)
    {
        m = n;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = m / 2 - 1; i >= 0; i--)
    {
        PercDown(a, i, m);
    }
    for (int i = m; i < n; i++)
    {
        cin >> tmp;
        if (tmp > a[0])
        {
            a[0] = tmp;
            PercDown(a, 0, m);
        }
    }
    HeapSort(a, m);
    cout << a[0];
    for (int i = 1; i < m; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}
