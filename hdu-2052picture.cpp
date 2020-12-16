#include<iostream>
using namespace std;
int main(){
	int n,m,i,j;
	while(cin >> n >> m){
		cout << "+";
		for(i = 1; i <= n; i++)
			cout << "-";
		cout << "+" << endl;
		for(i = 1; i <= m; i++){
			cout << "|";
			for(j = 1; j <= n; j++)
				cout << " ";
			cout << "|" << endl;
		}
		cout << "+";
		for(i = 1; i <= n; i++)
			cout << "-";
		cout << "+" << endl <<endl;
	}
}
