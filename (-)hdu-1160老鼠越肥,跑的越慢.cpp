#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Mice
{
	int w, s;
}mice[1010];
int main()
{
	Mice temp;
	int n = 1, res = 0;
	int dp[1010];
	while (cin >> mice[n++].w >> mice[n++].s);
	n--;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (mice[j].w > mice[j + 1].w || (mice[j].w == mice[j+1].w && mice[j].s < mice[j+1].s)) {
				temp = mice[j];
				mice[j] = mice[j + 1];
				mice[j + 1] = temp;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		dp[i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i - 1; j++) {
			if (mice[j].w < mice[i].w && mice[j].s > mice[i].s) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(dp[i], res);
	}
	cout << res << endl;
}
