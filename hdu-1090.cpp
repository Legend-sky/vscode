#include<iostream>
using namespace std;
int main(){
	int n,i = 1;
	int a,b;
	cin >> n;
	while(cin >> a >> b && i <= n){
		cout << a+b << endl;
		i++;
	}
} 
