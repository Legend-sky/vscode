#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n,i,step,mod,a[100001],b[100001],f;
	while(cin >> step >> mod){
		f = 1;
		for(i = 0; i < 100001; i++)
			a[i] = b[i] = 0;
		for(i = 1; i < mod; i++)
			a[i] = (a[i-1]+step)%mod;
		for(i = 0; i < mod; i++)
			b[a[i]] = 1;
		for(i = 0; i < mod; i++)
			if(b[i] != 1) f = 0;
		cout << right << setw(10) << step;
		cout << right << setw(10) << mod << "    ";
		if(f) cout << "Good Choice" << endl << endl;
		else cout << "Bad Choice" << endl << endl;
	}
}
