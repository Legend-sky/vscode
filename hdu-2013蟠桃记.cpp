#include<iostream>
using namespace std;
int main(){
	int n,sum,i;
	while(cin >> n){
		sum = 1;
		for(i = 1; i < n; i++){
			sum = (sum+1)*2;
		}
		cout << sum << endl;
	}
} 
