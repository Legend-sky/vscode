#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
double a[3005], c[3005];
int n;
int main()
{
	while (cin >> n)
	{
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		cin >> a[0] >> a[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> c[i];
		double res = 1.0 * n / (n + 1) * a[0] + 1.0 / (n + 1) * a[n + 1];
		double t = 2.0 * n;
		for (int i = 1; i <= n; i++)
		{
			res = res - t / (n + 1) * c[i];
			t -= 2.0;
		}
		cout << fixed << setprecision(2) << res << endl;
	}
	return 0;
}