/*
 * @Author: Whx
 * @Date: 2021-01-13 10:57:34
 * @LastEditTime: 2021-01-13 11:15:31
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
struct Node
{
    int degree, v;
    bool operator<(const Node &rhs) const
    {
        return degree > rhs.degree;
    }
} node[110];
bool edge[110][110];
int main()
{
    int t, n, d, x, y;
    bool flag;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(edge, 0, sizeof(edge));
        for (int i = 0; i < n; i++)
        {
            cin >> node[i].degree;
            node[i].v = i;
        }
        flag = 1;
        for (int k = 0; k < n && flag; k++)
        {
            sort(node + k, node + n);
            d = node[k].degree;
            x = node[k].v;
            if (d >= n - k)
            {
                flag = 0;
            }
            for (int j = 1; j <= d && flag; j++)
            {
                y = node[k + j].v;
                if (node[k + j].degree <= 0)
                    flag = 0;
                node[k + j].degree--;
                edge[x][y] = edge[y][x] = 1;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << edge[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
        cout << endl;
    }
    return 0;
}
