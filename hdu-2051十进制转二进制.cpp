#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int i,n,t,a[100];
	while(cin >> n){
		memset(a,0,sizeof(a));
		i = 0;
		while(n > 0){
			t = n % 2;
			a[i++] = t;
			n /= 2;
		}
		i--;
		for(;i >= 0; i--)
			cout << a[i];
		cout << endl;
	}
} 
