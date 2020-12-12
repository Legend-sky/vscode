/*
 * @Autor: Whx
 * @Date: 2020-11-09 09:05:14
 * @LastEditTime: 2020-11-09 09:20:36
 */
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[10005], b[10005], g[10005], k[10005], x, y;
bool f = false;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    cin >> x >> y;
    int i;
    for (i = n; i >= 1; i--)
    {
        if (x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i])
        {
            f = 1;
            break;
        }
    }
    if (f)
        cout << i << endl;
    else
        cout << "-1" << endl;
    return 0;
}