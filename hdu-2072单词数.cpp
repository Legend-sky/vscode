#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	map<string, int> dic;
	int start, len, i, j;
	string str;
	while (getline(cin,str))
	{
		if (str == "#") break;
		dic.clear();
		start = len = 0;
		string s = "";
		for (i = 0; i < str.length(); i++)
		{
			if (isalpha(str[i]))		//�Ӱ����ո�����кܶ࣬�п���ȫ�ǿո����Բ��ܸ��ݿո����жϵ�����
			{
				s.clear();
				for (j = i; isalpha(str[j]) && j < str.length(); j++)
					s += str[j];
				i = j;
				dic[s]++;
			}
		}
		cout << dic.size() << endl;
	}
	return 0;
}