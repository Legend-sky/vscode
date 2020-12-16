#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
	ll dp[51];
	int i,n;
	memset(dp,0,sizeof(dp));
	dp[1] = 3;
	dp[2] = 6;
	dp[3] = 6;
	for(i = 4; i <= 50; i++){
		dp[i] = dp[i-1] + 2*dp[i-2];
	}
	while(cin >> n){
		cout << dp[n] << endl;
	}
}
