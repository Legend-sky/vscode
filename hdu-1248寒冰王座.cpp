/*
 * @Author: Whx
 * @Date: 2020-11-29 22:08:15
 * @LastEditTime: 2020-11-30 22:45:08
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, t;
int w[3] = {150, 200, 350};
int f[20000];
int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> n;
        for (int i = 0; i < 3; i++)
            for (int j = w[i]; j <= n; j++)
                f[j] = max(f[j], f[j - w[i]] + w[i]);
        cout << n - f[n] << endl;
    }
    return 0;
}