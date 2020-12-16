#include<iostream>
using namespace std;
long long f[65];
void dfs(int n, long long m, int start, int end)
{
	int third = 6 - start - end;		//�������ӷֱ���1,2,3��Ϊ6
	long long mid = f[n];
	if (m == mid)
	{
		cout << n << ' ' << start << ' ' << end << endl;
		return;
	}
	if (m < mid)
		dfs(n - 1, m, start, third);
	else
		dfs(n - 1, m - mid, third, end);	//���ڵ�ǰ�����൱�ڽ��о��人ŵ���ĵ�����
}
int main()
{
	long long m;
	f[1] = 1;
	for (int i = 2; i <= 64; i++)
		f[i] = f[i - 1] * 2;
	int t;
	while (cin >> t)
	{
		while (t--) {
			int n;
			cin >> n >> m;
			dfs(n, m, 1, 3);
		}
	}
	return 0;
}