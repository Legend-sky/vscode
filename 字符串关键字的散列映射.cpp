/*
 * @Author: Whx
 * @Date: 2020-11-26 21:53:52
 * @LastEditTime: 2020-11-29 21:41:00
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
bool vis[10005];
map<string, int> m;
int main()
{
    memset(vis, 0, sizeof(vis));
    int n, p;
    string s;
    cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int sum = 0;
        if (s.size() == 1)
            sum = s[0] - 'A';
        else if (s.size() == 2)
            sum = (s[0] - 'A') * 32 + s[1] - 'A';
        else if (s.size() > 2)
            sum = 32 * 32 * (s[s.length() - 3] - 'A') + 32 * (s[s.length() - 2] - 'A') + s[s.length() - 1] - 'A';
        sum = sum % p;
        if (m[s] || !vis[sum])
        {
            m[s] = sum;
            vis[sum] = 1;
            cout << sum;
        }
        else
        {
            bool f = false;
            int y = 0, j = 1;
            while (!f)
            {
                y = (sum + j * j) % p;
                if (!vis[y])
                {
                    vis[y] = 1;
                    m[s] = y;
                    f = 1;
                    cout << y;
                    break;
                }
                y = (sum - j * j + p) % p;
                if (!vis[y])
                {
                    vis[y] = 1;
                    m[s] = y;
                    f = 1;
                    cout << y;
                    break;
                }
                j++;
            }
        }
        if (i < n - 1)
            cout << " ";
    }
    return 0;
}