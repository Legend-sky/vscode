#include<iostream>
using namespace std;
int main(){
	int i,j,n,count;
	while(cin >> n){
		count = 1;
		for(i = 1; i <= n/2; i++){
			if(n % i == 0) count++;
		}
		if(count % 2 == 0) cout << 0 << endl;
		else cout << 1 << endl;
	}
}
