#include<iostream>
using namespace std;
int main(){
	int month[2][12] ={{31,28,31,30,31,30,31,31,30,31,30,31},
					   {31,29,31,30,31,30,31,31,30,31,30,31}};
	int y,m,d,f,res;
	char c;
	while(cin >> y >> c >> m >> c >> d){
		f = 0;
		if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)		//判断是否为闰年：能被4整除但不能被100整除或者能被400整除 
			f = 1;
		res = d;
		while(--m){
			res += month[f][m-1];							//尽是坑啊，m月份忘记减一！！！ 
		}
		cout << res <<endl;
	}
}
