#include<iostream>
using namespace std;
int main(){
	char c[101];
	int i;
	while(gets(c)){
		c[0] -= 32;
		for(i = 1; c[i] != '\0'; i++){
			if(c[i-1] == ' '){
				c[i] -= 32;
			}
		}
		cout << c <<endl;
	}
} 
