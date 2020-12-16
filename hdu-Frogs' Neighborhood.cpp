#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
pair<int, int> pii[20];
bool cmp(int a, int b)
{
	return a > b;
}
bool cmp_pair(pair<int, int>pa, pair<int, int>pb)
{
	return pa.second > pb.second;
}
bool ismap(int a[],int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) sum += a[i];
	if (sum & 1) return false;
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			sort(i + a, n + a, cmp);
			if (i + a[i] >= n) return false;		//Òç³ö²»Âú×ã
			for (int j = i + 1; j <= i + a[i]; j++)
			{
				--a[j];
				if (a[j] < 0) return false;
			}			
		}
		if (a[n - 1] != 0) return false;
		return true;
	}
}
int main()
{
	ios::sync_with_stdio(!cin.tie(0)); cout.tie(0);
	int t, n, a[15], map[15][15];
	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			pii[i].first = i;
			pii[i].second = a[i];
		}
		if (!ismap(a, n)) cout << "NO" << endl << endl;
		else
		{
			cout << "YES" << endl;
			for (int i = 0; i < n - 1; i++)
			{
				sort(pii + i, pii + n, cmp_pair);
				for (int j = i + 1; j <= i + pii[i].second; j++)
				{
					map[pii[i].first][pii[j].first] = 1;
					map[pii[j].first][pii[i].first] = 1;
					--pii[j].second;
				}
			}
			for (int i = 0; i < n; i++)
			{
				int j;
				for (j = 0; j < n - 1; j++)
				{
					cout << map[i][j] << " ";
				}
				cout << map[i][j] << endl;
			}
			cout << endl;
		}
	}
	return 0;
}