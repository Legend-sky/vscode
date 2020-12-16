#include<iostream>
using namespace std;
int main(){
	int a[5],n,i,j;
	char b[5] = {'a','e','i','o','u'};
	char c[100];
	cin >> n;
	getchar();
	while(n--){
		for(i = 0; i < 5; i++)
			a[i] = 0;
		gets(c);
		for(i = 0; c[i] != '\0'; i++){
			for(j = 0; j < 5; j++){
				if(c[i] == b[j]){
					a[j]++;
				}
			}
		}
		for(i = 0; i < 5; i++){
			cout << b[i] << ':' << a[i] << endl;
		}
		if(n>=1)
			cout << endl;
	}
} 
