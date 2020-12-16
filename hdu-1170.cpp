#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	cout<<fixed<<setprecision(2);
	int n,a,b;
	char c;
	cin >> n;
	while(n--){
		cin >> c;
		cin >> a >> b;
		switch(c){
			case '+':
				cout << a+b << endl;
				break;
			case '-':
				cout << a-b << endl;
				break;
			case '*':
				cout << a*b << endl;
				break;
			case '/':
				if(a%b == 0)
					cout << a/b <<endl;
				else
					cout << 1.0*a/b << endl;
				break;
		}
	}
}
