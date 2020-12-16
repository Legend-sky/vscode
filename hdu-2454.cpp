#include<iostream>	//根据输入的图中每个点的度数判断能否成为简单图
#include<algorithm>
#include<cstring>
using namespace std;
bool cmp(int a, int b)
{
	return a < b;
}
int main()
{
	ios::sync_with_stdio(!cin.tie(NULL));
	int t, n, a[1005], f;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, cmp);
		while (1)
		{
			int sum = 0;
			for (int k = 0; k < n; k++) sum += a[k];
			if (sum & 1) { f = 0; break; }		//奇偶剪枝
			int i = a[n - 1];
			for (i = n - 2; i >= n - 2 - a[n - 1] + 1; i--) a[i]--;
			n--;
			sort(a, a + n, cmp);
			int j;
			for (j = 0; j < n; j++)
			{
				if (a[j] != 0) break;
			}
			if (j == n) { f = 1; break; }
			if (a[0] < 0) { f = 0; break; }
		}
		if (f) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}