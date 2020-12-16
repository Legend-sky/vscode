#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	double n, m, x, y;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		x = (n + sqrt(n * n - 4 * m)) / 2;
		y = m / x;
		if (x == (int)x && y == (int)y) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}