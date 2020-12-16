#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
	ll dp[10001];
	dp[1] = 2;
	int n,m,i;
	for(i = 2; i <= 10000; i++)
		dp[i] = dp[i-1] + 4*i - 3;
	cin >> n;
	while(n--){
		cin >> m;
		cout << dp[m] << endl;
	}
} 
