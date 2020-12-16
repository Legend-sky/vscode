#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
	ll dp[40];
	int i,n;
	memset(dp,0,sizeof(dp));
	dp[1] = 3;
	dp[2] = 8;
	for(i = 3; i < 40; i++)
		dp[i] = 2*(dp[i-1] + dp[i-2]);
	while(cin >> n){
		cout << dp[n] << endl;
	}
}
