/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-13 10:35:20
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct Node
{
	int st, en;
} node;
bool cmp(node a, node b)
{
	return a.en < b.en;
}
node a[105];
int n, ans, tmp;
int main()
{
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i].st >> a[i].en;
		sort(a, a + n, cmp);
		ans = 1;
		tmp = a[0].en;
		for (int i = 1; i < n; i++)
		{
			if (a[i].st >= tmp)
			{
				ans++;
				tmp = a[i].en;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
