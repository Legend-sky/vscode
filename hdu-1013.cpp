#include<iostream>
using namespace std;
int main(){
	char s[1000];
	int res,i;
	while(cin >> s){			//���������������cin.getline(s,1000)�ᱨ���� 
		if(s[0] == '0'){
			break;
		}
		res = 0;
		for(i = 0; s[i] != '\0'; i++){
			res += s[i] - '0';
			if(res > 9){
				res = res % 10 + res / 10;
			}
		}
		cout << res << endl;
	}
} 
