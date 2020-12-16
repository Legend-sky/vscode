#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	long long n, m, i, j;
	while (cin >> n >> m && n && m) {
		for (j = sqrt((double)2 * m); j > 0; j--) {		//1+2+3+...+sqrt(2*m)>m
			i = (2 * m / j + 1 - j) / 2;
			if ((2 * i + j - 1) * j == 2 * m)
				cout << '[' << i << ',' << i + j - 1 << ']' << endl;
		}
		cout << endl;
	}
}