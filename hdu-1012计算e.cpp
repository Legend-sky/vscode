#include<iostream>
#include<iomanip>
using namespace std;
int f(int m){
	if(m == 0 || m == 1) return 1;
	else return f(m-1)*m;
}
double e(int n){
	if(n == 0) return 1;
	else return e(n-1)+1.0/f(n);
}
int main(){
	int i;
	cout << "n e\n- -----------" << endl;
	for(i = 0; i <= 9; i++){
		if(i < 3) cout << i << ' ' << e(i) << endl;
		else cout << fixed << setprecision(9) << i << ' ' << e(i) << endl;
	}
	return 0;
}
