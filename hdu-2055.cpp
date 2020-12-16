#include<iostream>
using namespace std;
int main(){
	int n,i,y;
	char c;
	cin >> n;
	while(n--){
		cin >> c >> y;
		if(c >= 'A' && c <= 'Z')
			cout << y + (int)c - 64 << endl;
		else
			cout << y - (int)c + 96 << endl; 
	}
}
