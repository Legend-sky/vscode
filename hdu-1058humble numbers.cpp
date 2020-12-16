#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n, f[5], i;
	int dp[5850];
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	f[1] = f[2] = f[3] = f[4] = 1;
	for (i = 2; i <= 5842; i++) {
		dp[i] = min(min(2 * dp[f[1]], 3 * dp[f[2]]), min(5 * dp[f[3]], 7 * dp[f[4]]));
		if (dp[i] == dp[f[1]] * 2) f[1]++;
		if (dp[i] == dp[f[2]] * 3) f[2]++;
		if (dp[i] == dp[f[3]] * 5) f[3]++;
		if (dp[i] == dp[f[4]] * 7) f[4]++;
	}
	char s[3];
	while (cin >> n && n != 0) {
		if (n % 100 >= 11 && n % 100 <= 13) {
			strcpy_s(s, "th");
		}
		else {
			if (n % 10 == 1) strcpy_s(s, "st");
			else if (n % 10 == 2) strcpy_s(s, "nd");
			else if (n % 10 == 3) strcpy_s(s, "rd");
			else strcpy_s(s, "th");
		}
		cout << "The " << n << s << " humble number is " << dp[n] << '.' << endl;
	}
}