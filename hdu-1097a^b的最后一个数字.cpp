#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	long long a, b;
	int t, i, f[100];
	while (cin >> a >> b) {
		memset(f, 0, sizeof(f));
		t = a % 10;
		f[1] = t;
		for (i = 2; i <= b; i++) {
			f[i] = (f[i - 1] * t) % 10;
			if (f[i] == t) break;
		}
		int c = b % (i - 1);
		if (c == 0) {
			cout << f[i - 1] << endl;
		}
		else {
			cout << f[c] << endl;
		}
	}
}