#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
	cout << fixed << setprecision(2);
	double x1, x2, x3, x4;
	double y1, y2, y3, y4;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		if (y1 > y2)
			swap(y1, y2);
		if (x3 > x4) {
			swap(x3, x4);
			swap(y3, y4);
		}
		if (y3 > y4)
			swap(y3, y4);
		if (x3 >= x2 || y3 >= y2 || x1 >= x4 || y1 >= y4) {
			cout << "0.00" << endl;
		}
		else {
			cout << (min(x2, x4) - max(x1, x3)) * (min(y2, y4) - max(y1, y3)) << endl;
		}
	}
}