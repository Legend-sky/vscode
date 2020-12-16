#include<iostream>
using namespace std;
int main(){
	int i,n,m,res;
	cin >> n;
	while(n--){
		cin >> m;
		res = 3;
		for(i = 1; i <= m; i++){
			res = (res - 1) * 2; 
		}
		cout << res << endl;
	}
} 
