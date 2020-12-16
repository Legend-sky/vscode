#include<iostream>
using namespace std;
int sum;
void dfs(int m){		//也可以用递推,到达m的方式=到达m-1的方式加上到达m-2的方式
	int i;
	if(m == 0) return;
	if(m == 1){
		sum++;
		return;
	}
	for(i = 1; i <= 2; i++){
		dfs(m-i);
	}
	return;
}
int main(){
	int n,m;
	cin >> n;
	while(n--){
		sum = 0;
		cin >> m;
		dfs(m);
		cout << sum << endl;
	}
	return 0;
}
