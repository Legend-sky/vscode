#include<iostream>
using namespace std;
int main() {
	int i, j, flag, begin, end, a, b, f[51];
	long n;
	f[1] = f[2] = 1;
	while (cin >> a >> b >> n && (a || b || n)) {
		flag = 1;
		for (i = 3; i <= n && flag; i++) {
			f[i] = (a * f[i - 1] + b * f[i - 2]) % 7;
			for (j = 2; j < i; j++) {
				if (f[i] == f[j] && f[i - 1] == f[j - 1]) {
					begin = j;
					end = i;
					flag = 0;
					break;
				}
			}
		}
		if (flag) cout << f[n] << endl;
		else cout << f[begin + (n - end) % (end - begin)] << endl;
	}
	return 0;
}
