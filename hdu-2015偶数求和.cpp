#include<iostream>
using namespace std;
int main(){
	int n,m,i,j,res,count,k;
	while(cin >> n >> m){
		k = m;
		res = count = 0;					//不能忘记赋初值！！！ 
		for(i = 2; i <= 2*n; i = i + 2){
			if(m){
				res += i;
				m--;
				count ++;
			}
			if(m == 0 && i != 2*n){
				cout << res/count << ' ';
				res = 0;
				count = 0;
				m = k;
			}
			if(i == 2*n){
				cout << res/count << endl;
			}
		}
	}
} 
