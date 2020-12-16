#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[25], n;
bool used[25];
int isprime(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
void dfs(int x)
{
	int i, j;
	if (x == n && isprime(1 + a[x - 1])) {
		cout << 1;
		for (j = 1; j < n; j++)
			cout << ' ' << a[j];
		cout << endl;
		return;
	}
	for (i = 2; i <= n; i++) {
		if (!used[i] && isprime(i + a[x - 1])) {
			a[x] = i;
			used[i] = true;
			dfs(x + 1);
			used[i] = false;
		}
	}
	return;
}
int main()
{
	int num = 1;
	while (cin >> n) {
		memset(a, 0, sizeof(a));
		memset(used, false, sizeof(used));
		a[0] = 1;
		used[1] = true;
		cout << "Case " << num++ << ':' << endl;
		dfs(1);
		cout << endl;
	}
	return 0;
}