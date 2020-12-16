#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
	ll dp[51];
	int i,n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(i = 4; i <= 50; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	while(cin >> n){
		cout << dp[n] << endl;
	}
} 
