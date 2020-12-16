/*
��dp[i][0~3]��ʾ��ǰ״̬�ķ�����
i��ʾ����Ϊi���ַ���
0�����С�A����'C'�ĸ�����Ϊż��
1������'A'�ĸ���Ϊ���������С�C���ĸ���Ϊż��
2������'C'�ĸ���Ϊ���������С�A���ĸ���Ϊż��
3�����С�A����'C'�ĸ�����Ϊ����
Ȼ��ö�ٵ�i + 1���ַ����õ�״̬ת�Ʒ���
dp[i + 1][0] = dp[i][0] * 2 + dp[i][1] + dp[i][2];
dp[i + 1][1] = dp[i][1] * 2 + dp[i][0] + dp[i][3];
dp[i + 1][2] = dp[i][2] * 2 + dp[i][0] + dp[i][3];
dp[i + 1][3] = dp[i][3] * 2 + dp[i][1] + dp[i][2];
����Ϊ��DP[i] * P = DP[i + 1]
���ݾ���˷��Ľ���ɿɵã�DP[0] * P ^ n = DP[n]
��P ^ n���п����ݼ���
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
