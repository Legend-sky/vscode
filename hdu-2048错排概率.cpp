#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
typedef long long ll;
int main(){
	ll dp[21];
	ll sum[21];
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	dp[1] = 0;
	dp[2] = 1;
	int c,n,i,j;
	for(i = 3; i <= 20; i++)
		dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
	for(i = 1; i <= 20; i++){
		sum[i] = 1;
		for(j = 2; j <= i; j++){
			sum[i] *= j;
		}
	} 
	cin >> c;
	while(c--){
		cin >> n;
		cout << fixed << setprecision(2) << 100.0*dp[n]/sum[n] << '%' << endl;
	}
}
