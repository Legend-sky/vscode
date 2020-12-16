#include<iostream>
#include<cstring>
#include<algorithm>
#define lmax 251
using namespace std;
int a[lmax][101], b[lmax][101], c[5], i, j, k, p, v[5] = { 1,5,10,25,50 };	//硬币数还有个限制，要开个二维数组
int main()
{
	int n;
	while (cin >> n) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		a[0][0] = 1;
		for (i = 0; i < 5; i++)
			c[i] = n / v[i];		//c[i]记录每种硬币的最大数目
		for (i = 0; i <= min(100, n); i++)
			a[i][i] = 1;
		for (i = 1; i < 5; i++) {
			for (j = 0; j <= n; j++)
				for (k = 0; k + j <= n && k <= c[i] * v[i]; k += v[i])
					for (p = 0; p + k / v[i] <= 100; p++)
						b[k + j][p + k / v[i]] += a[j][p];
			for (k = 0; k <= n; k++) {
				for (p = 0; p <= 100; p++) {
					a[k][p] = b[k][p];
					b[k][p] = 0;
				}
			}
		}
		int res = 0;
		for (i = 0; i <= 100; i++) {
			res += a[n][i];
		}
		cout << res << endl;
	}
	return 0;
}