/*
设dp[i][0~3]表示当前状态的方案数
i表示长度为i的字符串
0代表含有‘A’和'C'的个数均为偶数
1代表含有'A'的个数为奇数，含有‘C’的个数为偶数
2代表含有'C'的个数为奇数，含有‘A’的个数为偶数
3代表含有‘A’和'C'的个数均为奇数
然后枚举第i + 1个字符，得到状态转移方程
dp[i + 1][0] = dp[i][0] * 2 + dp[i][1] + dp[i][2];
dp[i + 1][1] = dp[i][1] * 2 + dp[i][0] + dp[i][3];
dp[i + 1][2] = dp[i][2] * 2 + dp[i][0] + dp[i][3];
dp[i + 1][3] = dp[i][3] * 2 + dp[i][1] + dp[i][2];
设其为：DP[i] * P = DP[i + 1]
根据矩阵乘法的结合律可得：DP[0] * P ^ n = DP[n]
对P ^ n进行快速幂即可
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Matrix {
	int m[4][4];
};
const Matrix E = { 1,0,0,0,
				   0,1,0,0,
				   0,0,1,0,
				   0,0,0,1 
};
const Matrix P = { 2,1,1,0,
				   1,2,0,1,
				   1,0,2,1,
				   0,1,1,2 
};
Matrix muti(const Matrix& a, const Matrix& b)
{
	Matrix c;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			c.m[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % 100;
			}
		}
	}
	return c;
}
Matrix quickpow(long long m)
{
	Matrix res = E, a = P;
	while (m > 0)
	{
		if (m & 1) res = muti(res, a);
		a = muti(a, a);
		m >>= 1;
	}
	return res;
}
int main()
{
	int t, num;
	long long n;
	while (cin >> t && t)
	{
		num = 1;
		while (t--)
		{
			cin >> n;
			cout << "Case " << num++ << ": " << quickpow(n).m[0][0] << endl;
		}
		cout << endl;
	}
	return 0;
}
