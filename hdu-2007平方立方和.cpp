#include<iostream>
using namespace std;
int main(){
	int i,m,n,temp,res1,res2;
	while(cin >> m >> n){		//��m-n֮���������е�ż����ƽ�������������� 
		if(m > n){
			temp = m;
			m = n;
			n = temp; 
		}
		res1 = res2 = 0;
		for(i = m; i <= n; i++){
			if(i % 2 == 0)
				res1 += i*i;
			else
				res2 += i*i*i;
		}
		cout << res1 << ' ' << res2 <<endl;
	}
}
