#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,i,f;
	char c[60];
	cin >> n;							 
	getchar();							//�Ե��س���������������Ҳ���ж� 
	while(n--){
		f = 1;
		gets(c);						//�ַ���ֱ����gets����ܶ� 
		for(i = 0; c[i] != '\0'; i++)
		{
			if(!((c[0] >= 97 && c[0] <= 122) || (c[0] >= 65 && c[0] <= 90) || (c[0] == 95)))
			{
				f = 0;
				cout << "no" << endl;
				break;
			}
			if((c[i] >= 48 && c[i] <= 57) || (c[i] >= 97 && c[i] <= 122) ||
			   (c[i] >= 65 && c[i] <= 90) || (c[i] == 95)){
				f = 1;
			}
			else{
				f = 0;
				cout << "no" << endl;
				break;
			}
		}
		if(f) cout << "yes" << endl;
	}
} 
