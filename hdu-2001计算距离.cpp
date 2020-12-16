#include<iostream>
using namespace std;
int main() {
	int n, res, a;
	while (cin>>n) {
		res = 1;
		while (n--)
		{
			cin >> a;
			if (a % 2 == 1) res *= a;
		}
		cout << res << endl;
	}
	return 0;
}