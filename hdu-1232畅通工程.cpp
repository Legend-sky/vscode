/*
 * @Author: Whx
 * @Date: 2020-11-25 19:47:19
 * @LastEditTime: 2020-11-25 19:57:39
 */
#include <iostream>
#include <algorithm>
using namespace std;
int bin[1005];
int find(int x)
{
    int r = x;
    while (bin[r] != r)
        r = bin[r];
    return r;
}
void merge(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    if (fa != fb)
        bin[fa] = fb;
}
int main()
{
    int n, m;
    int p, q;
    while (cin >> n, n)
    {
        for (int i = 1; i <= n; i++)
            bin[i] = i;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> p >> q;
            merge(p, q);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (bin[i] == i)
                cnt++;
        cout << cnt - 1 << endl;
    }
    return 0;
}