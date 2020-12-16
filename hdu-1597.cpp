#include<iostream>
using namespace std;
int main(){
	int n,s;
	int k;
	cin >> k;
	while(k--){
		cin >> n;
		s = 1;
		while(n > s){
			n = n - s;
			s++;
		}
		if(n%9 == 0) cout << 9 <<endl;
		else cout << n%9 << endl;
	}
}
