#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n, x[27], dp[51];
	cin >> n;
	while (n--)
	{
		for (int i = 1; i <= 26; i++)
		{
			int a;
			cin >> a;
			x[i] = a;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= 26; i++)
			for (int j = 50; j >= i; j--)
				for (int k = 1; k <= x[i]; k++)
					if (j - k * i >= 0 && dp[j - k * i] != 0)
						dp[j] += dp[j - k * i];
		int sum = 0;
		for (int i = 1; i <= 50; i++) sum += dp[i];
		cout << sum << endl;
	}
	return 0;
}