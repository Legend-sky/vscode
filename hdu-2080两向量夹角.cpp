#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int t;
	double x1, y1, x2, y2, res;
	cin >> t;
	while (t--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		res = acos((x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2)));
		res = res * 180 / acos(-1);
		cout << fixed << setprecision(2) << res << endl;
	}
	return 0;
}