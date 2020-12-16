#include<iostream>
using namespace std;
int main(){
	int n,i,sum;
	while(cin >> n){
		sum = 0;
		for(i = 0; i <= n; i++){
			sum += i;
		}
		cout << sum << "\n" << endl;
	}
}
