#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int t, n;
	cin >> t;
	double res, k;
	while (t--)
	{
		cin >> n >> res;
		for (int i = 1; i < n; i++)
		{
			cin >> k;
			if (k > res) res = k;
		}
		cout << fixed << setprecision(2) << res << endl;
	}
	return 0;
}