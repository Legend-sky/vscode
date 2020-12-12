/*
 * @Autor: Whx
 * @Date: 2020-10-28 16:59:04
 * @LastEditTime: 2020-10-29 13:10:23
 */
#include <bits/stdc++.h>

using namespace std;

int n, k = 1;
int a[100005];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int sum, maxsum;
        int l, r, tmp;
        maxsum = a[1];
        sum = 0;
        l = r = tmp = 1;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
            if (sum > maxsum)
            {
                maxsum = sum;
                l = tmp;
                r = i;
            }
            if (sum < 0)
            {
                sum = 0;
                tmp = i + 1;
            }
        }
        cout << "Case " << k++ << ":" << endl;
        cout << maxsum << " " << l << " " << r << endl;
        if (t)
            cout << endl;
    }
    return 0;
}
