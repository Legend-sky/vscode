#include<iostream>
using namespace std;
int main(){
	int n,i,sum;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		sum = 0;
		for(i = 0; s[i] != '\0'; i++){
			if(s[i] >= '0' && s[i] <= '9') sum++;
		}
		cout << sum << endl;
	}
}
