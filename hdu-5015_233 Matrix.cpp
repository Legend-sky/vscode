#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int mod = 10000007;
int n;
struct Matrix {
	ll m[15][15];
	Matrix()
	{
		memset(m, 0, sizeof(m));
	}
};
Matrix multi(Matrix a, Matrix b)
{
	Matrix c;
	for (int i = 0; i <= n+2; i++)
		for (int j = 0; j <=n+2; j++)
			for (int k = 0; k <=n+2; k++)
				c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
	return c;
}
Matrix quickpow(Matrix a, ll x)
{
	Matrix res;
	for (int i = 1; i <= n + 2; i++)
		res.m[i][i] = 1;
	while (x)
	{
		if (x & 1) res = multi(res, a);
		a = multi(a, a);
		x >>= 1;
	}
	return res;
}
int main()
{
	ll m;
	while (cin >> n >> m)
	{
		Matrix mat, tem;
		mat.m[1][1] = 23;
		for (int i = 1; i <= n; i++)
			cin >> mat.m[i + 1][1];
		mat.m[n + 2][1] = 3;

		for (int i = 1; i <= n + 1; i++)
			tem.m[i][1] = 10;
		for (int i = 1; i <= n + 2; i++)
			tem.m[i][n + 2] = 1;
		for (int i = 1; i < n + 2; i++)
			for (int j = 2; j <= i; j++)
				tem.m[i][j] = 1;
		tem = quickpow(tem, m);
		mat = multi(tem, mat);

		cout << mat.m[n+1][1] << endl;
	}
	return 0;
}