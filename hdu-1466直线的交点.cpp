#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int dp[25][200];
	memset(dp,0,sizeof(dp));
	int n,i,j,a,b;
	dp[0][0] = 1;
	dp[1][0] = 1;
	for(n = 2; n <= 20; n++){
		dp[n][0] = 1;
		for(i = 1; i < n; i++){
			a = i;		//表示i条直线平行 
			b = n - i;	//除i条平行直线剩下的其他直线
			for(j = 0; j <= b*(b-1)/2; j++){		//b条直线最多有b * (b - 1) / 2个交点数
				if(dp[b][j]) dp[n][a*b + j] = 1;
			}
		}
	}
	while(cin >> n){
		for(i = 0; i <= n*(n-1)/2; i++){
			if(i == 0) 
				cout << i;
			else if(dp[n][i])
				cout << ' ' << i;
		}
		cout << endl;
	}
	return 0;
} 
