#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
	int n,m,i,t;
	ll dp[21],fac[21];
	memset(dp,0,sizeof(dp));
	dp[1] = 0;fac[0] = 1;
	dp[2] = 1;fac[1] = 1;
	for(i = 3; i <= 20; i++)
		dp[i] = (i - 1) * (dp[i-1] + dp[i-2]);
	for(i = 2; i <= 20; i++)
		fac[i] = fac[i-1] * i;
	cin >> t;
	while(t--){
		cin >> n >> m;
		cout << fac[n]/fac[m]/fac[n-m]*dp[m] << endl;
	}
}
