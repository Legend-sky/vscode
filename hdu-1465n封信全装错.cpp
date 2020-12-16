#include<iostream>
using namespace std;
int main(){
	int n,i;
	long long f[30];
	f[1] = 0;
	f[2] = 1;
	for(i = 3; i < 21; i++){
		f[i] = (f[i-1]+f[i-2])*(i-1);
	}
	while(cin >> n){
		cout << f[n] << endl;
	}
} 
