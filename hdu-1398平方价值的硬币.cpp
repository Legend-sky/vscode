#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int lmax = 301;
int c1[lmax], c2[lmax], f[lmax];
int n;
int GF(int x)
{
	int i, j, k;
	for (i = 0; i <= n; i++) {
		c1[i] = 1;
		c2[i] = 0;
	}
	for (i = 2; i <= 17; i++) {
		for (j = 0; j <= x; j++) {
			for (k = 0; k + j <= n; k += i * i) {
				c2[j + k] += c1[j];
			}
		}
		for (j = 0; j <= x; j++)
		{
			c1[j] = c2[j];
			c2[j] = 0;
		}
	}
	return c1[x];
}
int dp(int x)
{
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for (int i = 1; i <= 17; i++) {
		for (int j = 1; j <= 300; j++) {
			if (j - i * i >= 0)
				f[j] += f[j - i * i];
		}
	}
	return f[x];
}
int main()
{
	while (cin >> n && n){
		cout << GF(n) << endl;
		cout << dp(n) << endl;
	}
	return 0;
}
