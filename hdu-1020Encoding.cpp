#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,m,t,k,i,j;
	char a[10001],c;
	cin >> n;
	while(n--){
		cin >> a;
		c = a[0];
		t = 1;
		j = 0;
		for(i = 1; a[i] != '\0'; i++){
			if(a[i] == c) t++;
			else{
				if(t == 1){
					cout << c;
				}
				else{
					cout << t << c;
				}
				c = a[i];
				t = 1;
			}
		}
		if(t == 1)
			cout << c << endl;
		else
			cout << t << c << endl;
	}
}
