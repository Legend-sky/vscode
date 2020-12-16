/*如果最大堆-次大堆<=1，那么问题肯定有解：
我们可以从最大和次大里面每次拿一个，然后等他们和第三大堆相等的时候
，每次从三堆里面各拿一个，等他们和第四大堆相等的时候
，每次从四堆里面各拿一个，这样一直拿完所有堆。
问题变成了能不能使得最大堆-次大堆<=1，所以之前我们会从次大堆之外的那些堆里面取，
来让最大堆减少，如果能减到：最大堆-次大堆<=1，那么原问题有解。
能否减到要看：
sum - max - max2 >= max - max2 - 1
是否成立，其中sum为总和，max为最大堆，max2为次大。
整理得：
2 * sum - max >= max - 1
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t, n, k, maxn;
	long long sum;
	cin >> t;
	while (scanf("%d", &n) != EOF)
	{
		sum = maxn = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &k);
			sum += k;
			maxn = max(maxn, k);
		}
		if (sum - maxn + 1 >= maxn) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}