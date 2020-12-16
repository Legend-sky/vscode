#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int h, m, s, t;
	double x, y, a;		//x表示时针与12点的夹角，y表示分针与60的夹角，a表示时针和分针的夹角
	cin >> t;
	while (t--)
	{
		cin >> h >> m >> s;
		if (h >= 12) h -= 12;
		x = (h + (m + s / 60.0) / 60.0) * 30.0;
		y = (m + s / 60.0) * 6.0;
		a = abs(x - y);
		a > 180 ? a = 360 - a : a = a;
		cout << (int)a << endl;
	}
	return 0;
}