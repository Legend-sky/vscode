#include<iostream>
using namespace std;
int a[60] = {0,1,2,3};
int func(int x){
	if(x <= 3) return a[x];
	else return func(x-1) + func(x-3);
} 
int main(){
	int n;
	while(cin >> n && n != 0){
		cout << func(n) << endl;
	}
} 
