#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int i,f,n,m;
	char c[100];
	cin >> n;
	getchar();
	while(n--){
		gets(c);
		f = 1;
		m = strlen(c);
		for(i = 0; i < m/2; i++){
			if(c[i] != c[m-1-i]){
				f = 0; 
				break;
			}
		}
		if(f) cout << "yes" << endl;
		else cout << "no" <<endl; 
	}
}
