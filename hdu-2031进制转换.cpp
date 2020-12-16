#include<iostream>
using namespace std;
int main(){
	int n,r,f,i,j;
	char a[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char c[100];
	while(cin >> n >> r){
		f = 1;
		if(n < 0){
			f = -1;
			n = -n;
		}
		for(i = 0; n > 0; i++){
			c[i] = a[n%r];
			n = n/r;
		}
		if(f == -1) cout << '-';
		for(j = i-1; j >= 0; j--){
			cout << c[j];
		}
		cout <<endl;
	} 
} 
