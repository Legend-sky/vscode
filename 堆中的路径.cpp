/*
 * @Author: Whx
 * @Date: 2020-11-17 19:53:23
 * @LastEditTime: 2020-11-17 20:08:18
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, len = 0, a;
int h[1005], l[1005];
void push(int x)
{
    int i = ++len;
    while (h[i / 2] > x && i > 1)
    {
        h[i] = h[i / 2];
        i /= 2;
    }
    h[i] = x;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        push(a);
    }
    for (int i = 1; i <= m; i++)
        cin >> l[i];
    for (int i = 1; i <= m; i++)
    {
        cout << h[l[i]];
        for (int j = l[i] / 2; j >= 1; j /= 2)
        {
            cout << " " << h[j];
        }
        cout << endl;
    }
    return 0;
}