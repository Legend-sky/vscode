#include<iostream>
using namespace std;
int main(){
	int n,m,a,res;
	cin >> n;
	while(n--){
		cin >> m;
		res = 0;
		while(m--){
			cin >> a;
			res += a;
		}
		if(n == 0)
			cout << res << endl;
		else
			cout << res << endl << endl;
	}
} 
