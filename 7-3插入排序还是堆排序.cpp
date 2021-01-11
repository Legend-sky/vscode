/*
 * @Author: Whx
 * @Date: 2021-01-07 21:40:29
 * @LastEditTime: 2021-01-07 22:57:15
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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    if (b[1] > b[2]) //heapSort
    {
        int m = 0;
        for (int i = 3; i <= n; i++) //找到已经排好序的最前一个树为b[m]
        {
            if (b[1] < b[i])
            {
                m = i;
                break;
            }
        }
        int tmp = b[1];
        b[1] = b[m - 1]; //b[m-1]与b[1]交换位置的一步
        b[m - 1] = tmp;
        m -= 2;
        int num = 1, Max;
        for (; num * 2 <= m;) //左子树：num*2 右子树：num*2+1
        {
            if (num * 2 == m)
                Max = m;
            else
            {
                Max = b[num * 2] < b[num * 2 + 1] ? num * 2 + 1 : num * 2;
            }
            if (b[num] < b[Max])
            {
                swap(b[Max], b[num]);
                num = Max;
            }
            else
                break;
        }
        cout << "Heap Sort" << endl
             << b[1];
        for (int i = 2; i <= n; i++)
            cout << " " << b[i];
    }
    else //InsertSort
    {
        int need = 0, tmp;
        bool next = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int j = i; j > 1; j--)
            {
                if (a[j - 1] > a[j])
                {
                    swap(a[j - 1], a[j]);
                }
                else
                    break;
            }
            if (next)
            {
                cout << "Insertion Sort" << endl
                     << a[1];
                for (int i = 2; i <= n; i++)
                {
                    cout << " " << a[i];
                }
                return 0;
            }
            for (int i = 1; i <= n; i++)
            {
                if (b[i] != a[i]) //都相等，说明来到了b的这一步
                {
                    next = 0;
                    break;
                }
                next = 1;
            }
        }
    }
    return 0;
}
