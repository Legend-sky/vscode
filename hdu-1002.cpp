#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,i,cs=0,n1,n2,nmax;
	char x[1001],y[1001];
	int a[1001],b[1001],res[1003];
	cin >> n;
	while(n--){
		cs++;
		cin >> x >> y;
		n1 = strlen(x);
		n2 = strlen(y);
		strrev(x);
		strrev(y);
		n1 > n2 ? nmax = n1 : nmax = n2;
		for(i = 0; i < 1001; i++)
			a[i] = b[i] = res[i] = 0;			//Êý×éÇåÁã£¡£¡£¡ 
		for(i = 0; i < n1; i++)
			a[i] = x[i] - '0';
		for(i = 0; i < n2; i++)
			b[i] = y[i] - '0';
		for(i = 0; i < nmax; i++){
			res[i] = a[i] + b[i];
			res[i+1] = 0;
		}
		for(i = 0; i < nmax; i++){
			if(res[i] > 9){
				res[i] = res[i]%10;
				res[i+1]++;
			}
		}
		strrev(x);
		strrev(y);
		if(res[i] == 0) i = nmax - 1;
		else i = nmax;
		cout << "Case " << cs << ":" << endl;
		cout << x << " + " << y << " = ";
		for(; i >= 0; i--)
			cout << res[i];
		if(n >= 1)
			cout << endl << endl;
		else if(n == 0) cout << endl;
	}
}
