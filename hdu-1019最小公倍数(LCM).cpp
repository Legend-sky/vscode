#include<iostream>
using namespace std;
int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}
int main() {
	int n, m, a, b, i;
	long long res;
	cin >> n;
	while (n--) {
		cin >> m;
		cin >> a;
		res = a;
		if (m == 1) {
			cout << res << endl;
		}
		else {
			for (i = 1; i < m; i++) {
				cin >> b;
				res = res * b / gcd(res, b);
			}
			cout << res << endl;
		}
	}
	return 0;
}
