#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
typedef struct Node {
	int price, weight;
}node;
node dami[1005];
bool cmp(node a, node b)
{
	return a.price < b.price;
}
int main()
{
	ios::sync_with_stdio(!cin.tie(NULL));
	cout << fixed << setprecision(2);
	int t, money, n;
	double ans;
	cin >> t;
	while (t--)
	{
		cin >> money >> n;
		for (int i = 0; i < n; i++) cin >> dami[i].price >> dami[i].weight;
		sort(dami, dami + n, cmp);
		ans = 0;
		for (int i = 0; (i < n) && (money > 0); i++)
		{
			if (money >= dami[i].price * dami[i].weight)
			{
				money -= (dami[i].price * dami[i].weight);
				ans += dami[i].weight;
			}
			else
			{
				ans += (1.0 * money / dami[i].price);
				money = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}