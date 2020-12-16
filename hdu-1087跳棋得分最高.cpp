#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010], dp[1010];
int main()
{
	int i, j, n, res;
	while (cin >> n && n != 0) {
		res = 0;							//好久没错过的地方错了，还是要更加仔细啊。
		for (i = 1; i <= n; i++) {
			cin >> a[i];
			dp[i] = a[i];
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= i - 1; j++) {
				if (a[i] > a[j]) {
					dp[i] = max(dp[i], dp[j] + a[i]);
				}
			}
			res = max(res, dp[i]);
		}
		cout << res << endl;
	}
	return 0;
}