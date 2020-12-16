#include<iostream>
using namespace std;
int main() {
	int a, b, res, i;
	while (cin >> a >> b && (a != 0 || b != 0)) {
		/*res = a;
		for (i = 1; i < b; i++) {
			res = res * a % 1000;
		}*/
		//快速幂优化
		res = 1;
		while (b)
		{
			if (b & 1) res = res * a % 1000;
			a = a * a % 1000;
			b >>= 1;
		}
		cout << res << endl;
	}
}
