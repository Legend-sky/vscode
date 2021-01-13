/*
 * @Author: Whx
 * @Date: 2021-01-11 16:45:27
 * @LastEditTime: 2021-01-11 17:14:28
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
const int N = 1e6 + 7;
int a[N];
void PerDown(int a[], int p, int n)
{
    int parent, child;
    int x = a[p];
    for (parent = p; (parent * 2 + 1) < n; parent = child)
    {
        child = parent * 2 + 1;
        if (child != n - 1 && a[child] > a[child + 1])
        {
            child++;
        }
        if (x < a[child])
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
        PerDown(a, 0, i);
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin  436ms
    //scanf 483ms
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(a, 0, sizeof(a));
        if (n < m)
        {
            m = n;
        }
        for (int i = 0; i < m; i++)
        {
            //cin >> a[i];
            scanf("%d", &a[i]);
        }
        for (int i = m / 2 - 1; i >= 0; i--) //调整有m个元素的最小堆
        {
            PerDown(a, i, m);
        }
        int tmp;
        for (int i = m + 1; i <= n; i++)
        {
            //cin >> tmp;
            scanf("%d", &tmp);
            if (tmp > a[0])
            {
                a[0] = tmp;
                PerDown(a, 0, m);
            }
        }
        HeapSort(a, m);
        //cout << a[0];
        printf("%d", a[0]);
        for (int i = 1; i < m; i++)
        {
            //cout << " " << a[i];
            printf(" %d", a[i]);
        }
        //cout << endl;
        printf("\n");
    }
    return 0;
}
