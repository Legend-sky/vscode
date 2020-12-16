#include<iostream>
using namespace std;
int main(){
	int n,a,i,sum;
	while(cin >> n && n != 0){
		sum = 0;
		for(i = 0; i < n; i ++){
			cin >> a;
			sum += a;
		}
		cout << sum << endl;
	}
}
