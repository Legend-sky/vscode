#include<iostream>
using namespace std;
int main(){
	char ch[3],temp;
	int i,j;
	while(cin >> ch){
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3 - i - 1; j++){
				if(ch[j] > ch[j+1]){
					temp = ch[j];
					ch[j] = ch[j+1];
					ch[j+1] = temp;
				}
			}
		}
		for(i = 0; i < 2; i++){
			cout << ch[i] << ' ';
		}
		cout << ch[2] << endl;
	}
} 
