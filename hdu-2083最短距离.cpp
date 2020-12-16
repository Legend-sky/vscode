#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t, n, a[505], res;
	cin >> t;
	while (t--)
	{
		res = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
			res += abs(a[i] - a[n / 2]);
		cout << res << endl;
	}
	return 0;
}