/*
 * @Author: Whx
 * @Date: 2020-11-18 18:28:17
 * @LastEditTime: 2020-11-23 20:29:40
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, f[500005], v[55], num;
int v_sum;
int main()
{
    while (cin >> n && n > 0)
    {
        memset(f, 0, sizeof(f));
        v_sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i] >> num;
            v_sum += v[i] * num;
        }
        int m = v_sum / 2;
        for (int i = 0; i < n; i++)
            for (int j = v[i]; j <= m; j++)
                f[j] = max(f[j], f[j - v[i]] + v[i]);
        cout << v_sum - f[m] << " " << f[m] << endl;
    }
    return 0;
}