/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-10 19:38:22
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 10000 //系数可能很大
using namespace std;
/*int main()	15ms
{
	int n, m, t, a[10], b[12], dp[50];
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> n >> m;
		for (int i = 0; i < m; i++)
			cin >> a[i] >> b[i];
		dp[0] = 1;
		for (int i = 0; i < m; i++)
			for (int j = n; j >= a[i]; j--)
				for (int k = 1; k <= b[i]; k++)
					if (j - k * a[i] >= 0 && dp[j - k * a[i]] != 0)
						dp[j] = dp[j] + dp[j - k * a[i]];
		cout << dp[n] << endl;
	}
	return 0;
}*/
//2:dfs 124ms
/*int f[10];
int n, k, sum;
void dfs(int s, int t)
{
	if (s == n)
		sum++;
	if (s > n)
		return;
	for (int i = t + 1; i < 10; i++)
		for (int j = 1; j <= f[i]; j++)
			dfs(s + i * j, i);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		sum = 0;
		cin >> n >> k;
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			f[a] = b;
		}
		for (int i = 1; i < 9; i++)
			for (int j = 1; j <= f[i]; j++)
				dfs(i * j, i);
		cout << sum << endl;
	}
}*/
//3：Generation function
int t, n, k, a, b;
int aa[9];			  //表示学分为i的课有aa[i]门。
int c1[INF], c2[INF]; //c1用来存储第一个因式的各个系数，c2用来临时存储系数
int main()
{
	cin >> t;
	while (t--)
	{
		memset(aa, 0, sizeof(aa));
		cin >> n >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> a >> b;
			aa[a] += b; //防止多次出现相同学分的课程（多次出现则相加）
		}
		memset(c1, 0, sizeof(c1));	 //存储第一个因式的系数（直到只剩下一个因式（k轮循环完毕））
		memset(c2, 0, sizeof(c2));	 //临时存储x^的系数，每次循环（总共K次循环）完清零
		c1[0] = 1;					 //在k个因式最前面加一个因式“1”，即x^0的系数为1，后面k个因式循环处理（此时有k+1个因式）
		for (int i = 1; i <= k; i++) //处理后面k个因式
		{
			for (int j = 0; j <= n; j++) //j代表第一个因式的x的各个指数
			{
				for (int s = 0; s * i + j <= n && s <= aa[i]; s++) //s代表s个同一学分的课（范围是0到aa[i]）
				{												   //s*i + j <= n用来筛掉相乘指数大于n的项，降低时间复杂度
					c2[s * i + j] += c1[j];						   //不同的s,i,j组合的s*i + j的值可能相同
				}
			}
			for (int j = 0; j <= n; j++) //前面两个因式相乘合并为一个因式
			{							 //此时上一步相乘得到的因式的系数存储在c2，需要转移到c1
				c1[j] = c2[j];			 //因为c1用来存储第一个因式的系数，此时还剩(K+1-i)个因式
				c2[j] = 0;				 //清空临时存储池
			}
		}
		cout << c1[n] << endl;
	}
	system("pause");
	return 0;
}