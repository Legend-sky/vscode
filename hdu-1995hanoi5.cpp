/*
经典汉诺塔,每块需要移动的次数
第一块就是2^(n-1)
第二块就是2^(n-2)
第三块就是2^(n-3)
...
第n块就是1次
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long f[65];
	f[1] = 1;
	for (int i = 2; i <= 60; i++)
		f[i] = 2 * f[i - 1];
	int n, m, t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cout << f[n - m + 1] << endl;
	}
	return 0;
}