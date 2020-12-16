#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int x1, x2, y1, y2, n, c1, c2, i;
	double res;
	cin >> n;
	while (n--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		c1 = x1 + y1;
		c2 = x2 + y2;
		if (c1 > c2)
		{
			swap(x1, x2);
			swap(y1, y2);
			swap(c1, c2);
		}
		res = 0;
		if (c1 == c2) cout << fixed << setprecision(3) << abs(y2 - y1) * sqrt(2) << endl;
		else {
			for (i = c1; i <= c2; i++)
			{
				if (i == c1) res += (y1 * sqrt(2) + sqrt(i * i + (i + 1) * (i + 1)));
				else if (i == c2) res += (c2 - y2) * sqrt(2);
				else res += (sqrt(i * i + (i + 1) * (i + 1)) + i * sqrt(2));
			}
			cout << fixed << setprecision(3) << res << endl;
		}
	}
	return 0;
}