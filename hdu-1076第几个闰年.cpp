#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n, t, y, i, j, temp;
	cin >> t;
	while (t--) {
		cin >> y >> n;
		temp = 0;
		for (i = y; temp < n; i++) {
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
				temp++;
			}
		}
		cout << i - 1 << endl;
	}
	return 0;
}