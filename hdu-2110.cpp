/*
 * @Author: Whx
 * @Date: 2021-01-10 19:34:23
 * @LastEditTime: 2021-01-10 19:54:14
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int c1[10005], c2[10005];
int p[105], m[105];
int main()
{
    int n;
    while (cin >> n, n)
    {
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i] >> m[i];
            sum += p[i] * m[i];
        }
        int t = sum / 3;
        if (sum % 3 != 0)
        {
            cout << "sorry" << endl;
            continue;
        }
        for (int i = 0; i <= p[1] * m[1] && i <= t; i += p[1])
        {
            c1[i] = 1;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= t; j++)
            {
                for (int k = 0; k <= p[i] * m[i] && j + k <= t; k += p[i])
                {
                    c2[j + k] += c1[j];
                }
            }
            for (int j = 0; j <= t; j++)
            {
                c1[j] = c2[j] % 10000;
                c2[j] = 0;
            }
        }
        if (c1[t] == 0)
        {
            cout << "sorry" << endl;
        }
        else
        {
            cout << c1[t] << endl;
        }
    }
    return 0;
}