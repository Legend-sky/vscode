#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool isprime(int n) {
	bool f = true;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) {
			f = false;
			break;
		}
	return f;
}
int main()
{
	int m, a, b, p, q, i, j, maxres;
	int sushu[2000];
	sushu[1] = 1;
	int count = 1;
	for (i = 2; i <= 10000; i++) {
		if (isprime(i)) {
			sushu[++count] = i;
		}
	}
	while (cin >> m >> a >> b) {
		if (m == 0 && a == 0 && b == 0) break;
		maxres = -1;
		p = q = 0;
		bool v = false;
		for (i = count; i >= 1; i--) {		//sushu[i]就是p
			for (j = i; j <= count; j++) {	//sushu[j]就是q
				if (sushu[j] > m || sushu[j] * sushu[i] > m || sushu[i] * b < sushu[j] * a) break;
				if (sushu[i] * sushu[j] <= m && b * sushu[i] >= sushu[j] * a && maxres < sushu[i] * sushu[j]) {
					maxres = sushu[i] * sushu[j];
					q = sushu[j];
					p = sushu[i];
				}
			}
		}
		cout << p << ' ' << q << endl;
	}
}