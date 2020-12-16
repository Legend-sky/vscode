#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;
int res[10000];
int main()
{
	int n, i, j, jinwei, weishu;
	while (cin >> n) {
		memset(res, 0, sizeof(res));
		res[0] = 1;
		weishu = 0;
		for (i = 1; i <= n; i++) {
			jinwei = 0;
			for (j = 0; j <= weishu; j++) {
				res[j] = res[j] * i;
				if (j > 0 && res[j - 1] >= 10000) {
					res[j] = res[j] + res[j - 1] / 10000;
					res[j - 1] = res[j - 1] % 10000;
				}
				if (res[weishu] >= 10000) weishu++;
			}
		}
		cout << res[weishu];
		//printf("%d",res[weishu]);
		for (i = weishu - 1; i >= 0; i--)
			cout << setw(4) << setfill('0') << res[i];
			//printf("%04d",res[i]);
		cout << endl;
		//printf("\n");
	}
	return 0;
}