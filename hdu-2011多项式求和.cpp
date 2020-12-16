#include<iostream>
#include<iomanip>
using namespace std;
double func(int x){
	int i,f = 1;
	double res;
	for(i = 1; i <= x; i++){
		res += 1.0/i*f;
		f = -f;
	}
	return res;
}
int main(){
	cout << fixed << setprecision(2);
	int n,m;
	double res;
	cin >> n;
	while(n--){
		cin >> m;
		res = func(m);
		cout << res << endl;
	} 
}
