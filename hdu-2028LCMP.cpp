#include<iostream>
using namespace std;
int gcd(int m, int n){
	if(m%n == 0) return n;
	else return gcd(n,m%n);
}
int main(){
	int n,i,m;
	long long k;		//long long²ÅÄÜ¹ý...
	while(cin >> n && n > 0){
		cin >> k;
		if(n == 1){
			cout << k << endl;
			continue;
		}
		for(i = 1; i < n; i++){
			cin >> m;
			k = k*m/gcd(k,m);
		}
		cout << k << endl;
	}
	return 0;
}
