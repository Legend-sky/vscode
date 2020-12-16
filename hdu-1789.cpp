#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef struct Node {
	int de, re;
}node;
node p[1005];
int vis[1005];
bool cmp(node a, node b)
{
	return a.re > b.re;
}
int main()
{
	ios::sync_with_stdio(!cin.tie(NULL));
	int t, n;
	cin >> t;
	while (t--)
	{
		int ans = 0, f;
		memset(vis, 0, sizeof(vis));	//0 stand for unvisted
		cin >> n;
		for (int i = 0; i < n; i++) cin >> p[i].de;
		for (int i = 0; i < n; i++) cin >> p[i].re;
		sort(p, p + n, cmp);
		for (int i = 0; i < n; i++)
		{
			f = 1;
			for (int j = p[i].de; j >= 1; j--)
			{
				if (!vis[j])
				{
					vis[j] = 1;
					f = 0;
					break;
				}
			}
			if (f) ans += p[i].re;
		}
		cout << ans << endl;
	}
	return 0;
}