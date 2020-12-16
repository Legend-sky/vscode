#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	cout << fixed << setprecision(2);
	double a;
	while(cin >> a){
		if(a < 0){
			a = -a;
		}
		cout << a << endl;
	}
}
