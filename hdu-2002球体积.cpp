#include<iostream>
#include<iomanip>
const double PI = 3.1415927;
using namespace std;
int main(){
	cout << fixed << setprecision(3);
	double r;
	while(cin >> r){
		cout << 1.0*4/3*PI*r*r*r <<endl;
	}
} 
