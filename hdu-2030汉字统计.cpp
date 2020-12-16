#include<iostream>
using namespace std;
int main(){
	int i,n,res;
	char c[1000];
	cin >> n;
	getchar();
	while(n--){
		res = 0;
		gets(c);
		for(i = 0; c[i] != '\0'; i++){
			if(c[i] < 0){			//一个汉字在字符串中是以两个负的字符形式存储
				res++;				//汉字机内码在计算机的表达方式的描述是，使用二个字节，每个字节最高位一位为1。 
				i++;				//计算机中,补码第一位是符号位,1 表示为负数,所以 汉字机内码的每个字节表示的十进制数都是负数
			}
		}
		cout << res << endl;
	}
} 
