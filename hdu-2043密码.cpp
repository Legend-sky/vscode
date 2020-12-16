#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int i,n,len,a[5],res;
	char c[55];
	cin >> n;
	getchar();
	while(n--){
		a[1] = a[2] = a[3] = a[4] = 0;
		res = 0;
		gets(c);
		len = strlen(c);
		if(len < 8 || len > 16) cout << "NO" << endl;
		else{
			for(i = 0; i < len; i++){
				if(c[i] >= 'A' && c[i] <= 'Z')
					a[1]++;
				else if(c[i] >= 'a' && c[i] <= 'z')
					a[2]++;
				else if(c[i] >= '0' && c[i] <= '9')
					a[3]++;
				else if(c[i] == '~' || c[i] == '!' || c[i] == '@' || c[i] == '#' 
					 || c[i] == '$' || c[i] == '%' || c[i] == '^') a[4]++;
			}
			for(i = 1; i < 5; i++){
				if(a[i] != 0) res++;
			}
			if(res >= 3) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
