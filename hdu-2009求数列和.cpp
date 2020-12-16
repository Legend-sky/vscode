#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	cout << fixed << setprecision(2);
	int m;
	double n,res;
	while(cin >> n >> m){
		res = n;
		while(--m){
			res += sqrt(n);
			n = sqrt(n);
		}
		cout << res << endl;
	}
} 
