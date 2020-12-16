#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1000010;
int m, n;
int num[N];		//长度超过一百万的数组不能定义在函数内部，否则造成栈溢出
int dp[N];		//dp[j]存储以num[j]结尾的前j个数中，分成i段的最大值
int pre[N];		//pre[j]存储前j个数中（不一定以num[j]结尾），分成i段的最大值
int main()
{
	int i, j, sum;
	while (cin >> m >> n) {
		for (i = 1; i <= n; i++)
			cin >> num[i];
		memset(dp, 0, sizeof(dp));
		memset(pre, 0, sizeof(pre));
		for (i = 1; i <= m; i++) {		//外层循环找有几对
			sum = INT_MIN;
			for (j = i; j <= n; j++) {		//内层循环找最大
				dp[j] = max(dp[j - 1], pre[j - 1]) + num[j];
				pre[j - 1] = sum;
				sum = max(sum, dp[j]);
			}
		}
		cout << sum << endl;
	}
}