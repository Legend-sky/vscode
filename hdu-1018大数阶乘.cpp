#include<iostream>
#include<cmath>
using namespace std;	//斯特林公式:数字较大时计算阶乘的。n->无穷大时,n!->sqrt(2*pai*n)*pow(n/e,n)
int main(){
	int n,a,i,res;
	double sum;
	cin >> n;
	while(n--){
		sum = 0;
		cin >> a;
		if(a == 1){
			cout << 1 <<endl;
		}
		else{
			for( i = 2; i <= a; i++){
				sum += log10(i);	//1*2*3*4*5 = n,两边取对数: log10(1)+log10(2)+log10(3)+log10(4)+log10(5) = log10(n) = n的位数 
			}
			res = (int)sum + 1;		//log10(n)取整就是该数字的位数减一；例如log10(100) = 2,(int)log10(200) = 2  
			cout << res << endl;
		}
	}
}
