#include<iostream>
using namespace std;
int main(){
	double a,b,c;
	int n;
	cin >> n;
	while(n--){
		cin >> a >> b >> c;
		if(a + b > c && a + c > b && b + c > a){
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
}
