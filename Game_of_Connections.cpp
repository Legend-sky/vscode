/*
 * @Autor: Whx
 * @Date: 2020-10-28 13:27:42
 * @LastEditTime: 2020-10-28 14:01:14
 */
#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int a[105][100];
int b[100];
int n;

inline void solve(int n)
{
    int i, j, len, carry, temp;
    a[1][0] = b[1] = 1;
    len = 1;
    for (i = 2; i <= 100; i++)
    {
        for (j = 0; j < len; j++)
            a[i][j] = a[i - 1][j] * (4 * i - 2);
        carry = 0;
        for (j = 0; j < len; j++)
        {
            temp = a[i][j] + carry;
            a[i][j] = temp % 10;
            carry = temp / 10;
        }
        while (carry)
        {
            a[i][len++] = carry % 10;
            carry /= 10;
        }
        carry = 0;
        for (j = len - 1; j >= 0; j--)
        {
            temp = carry * 10 + a[i][j];
            a[i][j] = temp / (i + 1);
            carry = temp % (i + 1);
        }
        while (!a[i][len - 1])
            len--;
        b[i] = len;
    }
    for (i = b[n] - 1; i >= 0; i--)
        cout << a[n][i];
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n && n != -1)
        solve(n);
    return 0;
}
