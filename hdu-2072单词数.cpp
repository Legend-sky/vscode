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
			if (isalpha(str[i]))		//坑啊，空格可能有很多，有可能全是空格，所以不能根据空格来判断单词数
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