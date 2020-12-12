/*
 * @Author: Whx
 * @Date: 2020-11-26 21:53:52
 * @LastEditTime: 2020-11-26 22:17:14
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;

bool v[10005];
map<string, int> m;
int main()
{
    int n, p;
    cin >> n >> p;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int x = 0;
        if (s.size() == 1)
        {
            x = s[0] - 'A';
        }
        else if (s.size() == 2)
        {
            x = 32 * (s[0] - 'A') + s[1] - 'A';
        }
        else if (s.size() > 2)
        {
            x = 32 * 32 * (s[s.length() - 3] - 'A') + 32 * (s[s.length() - 2] - 'A') + s[s.length() - 1] - 'A';
        }
        x = x % p;
        if (m[s] || !v[x])
        {
            v[x] = true;
            m[s] = x;
            cout << x;
        }
        else
        {
            bool flag = false;
            int j = 1;
            int y = 0;
            while (flag == false)
            {
                y = (x + j * j) % p;
                if (!v[y])
                {
                    v[y] = true;
                    flag = true;
                    m[s] = y;
                    cout << y;
                    break;
                }
                y = (x - j * j + p) % p;
                if (!v[y])
                {
                    v[y] = true;
                    flag = true;
                    m[s] = y;
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