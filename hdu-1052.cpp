#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, tian[1005], qi[1005], ans;
bool cmp(int a, int b)
{
	return a < b;
}
int main()
{
	ios::sync_with_stdio(!cin.tie(NULL));
	while (cin >> n && n)
	{
		ans = 0;
		for (int i = 0; i < n; i++) cin >> tian[i];
		for (int i = 0; i < n; i++) cin >> qi[i];
		sort(tian, tian + n, cmp);
		sort(qi, qi + n, cmp);
		int i = 0, j = n - 1;
		int p = 0, q = n - 1;
		for (int k = 0; k < n; k++)
		{
			if (tian[i] > qi[p])	//田忌最慢的马比齐王最慢的马快，比慢马
			{
				i++;
				p++;
				ans++;
			}
			else if (tian[i] < qi[p])	//田忌最慢的马比齐王最慢的马慢，用慢马消耗齐王快马
			{
				i++;
				q--;
				ans--;
			}
			else		//田忌最慢的马和齐王最慢的马一样
			{
				if (tian[j] > qi[q])	//如果田忌最快的马比齐王最快的马快，比快马
				{
					j--;
					q--;
					ans++;
				}
				else if (tian[i] < qi[q])	//如果田忌最快的马比齐王最快的马慢或者相等，用田忌的慢马消耗快马
				{
					i++;
					q--;
					ans--;
				}
			}
		}
		cout << ans * 200 << endl;
	}
	return 0;
}