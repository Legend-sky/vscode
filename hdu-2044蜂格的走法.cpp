#include<iostream>
using namespace std;
int main(){
	int i,n,a,b;
	long long dp[51];
	dp[1] = 1;
	dp[2] = 2;
	for(i = 3; i <= 50; i++)
		dp[i] = dp[i-1] + dp[i-2];
	cin >> n;
	while(n--){
		cin >> a >> b;
		cout << dp[b-a] << endl;
	}
} 
