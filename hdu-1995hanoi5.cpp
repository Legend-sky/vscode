/*
���人ŵ��,ÿ����Ҫ�ƶ��Ĵ���
��һ�����2^(n-1)
�ڶ������2^(n-2)
���������2^(n-3)
...
��n�����1��
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