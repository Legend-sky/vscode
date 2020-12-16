#include<iostream>
using namespace std;
int main(){
	int n,u,d,t,s,f;
	while(cin >> n >> u >> d && (n || u || d)){
		s = t = 0;
		f = 1;
		while(s < n){
			if(f){
				s += u;
				t++;
				f = 0;
			}
			else{
				s -= d;
				t++;
				f = 1;
			}
		}
		cout << t <<endl;
	}
}
