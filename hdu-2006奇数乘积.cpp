#include<iostream>
using namespace std;
int main(){
	int a,n,sum;
	while(cin >> n){
		sum = 1;
		while(n--){
			cin >> a;
			if(a % 2 == 1){
				sum *= a;
			}
		}
		cout << sum <<endl;
	} 
} 
