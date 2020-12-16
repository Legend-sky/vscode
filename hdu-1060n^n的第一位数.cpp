#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double n,m;
	int res;
	cin >> m;
	while(m--){
		cin >> n;
		n = n*log10(n);
		n = n - (long long)n;
		res = pow(10,n);
		cout << res << endl;
	}
	return 0;
} 
