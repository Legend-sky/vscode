/*
 * @Author: Whx
 * @Date: 2020-10-23 10:57:11
 * @LastEditTime: 2020-11-16 19:31:47
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
bool cmp(char pre, char cur) //要出栈，返回true
{
	if (cur == '(' || pre == '(')
		return false;
	if (cur == ')')
		return true;
	if (cur == '+' || cur == '-')
		return true;
	else if (cur == '*' || cur == '/')
	{
		if (pre == '*' || pre == '/')
			return true;
		else if (pre == '+' || pre == '-')
			return false;
	}
}
int main()
{
	ios::sync_with_stdio(!cin.tie(NULL));
	stack<char> s;
	stack<double> q;
	string end; //存放后缀表达式
	char c[100];
	cin >> c;
	for (int i = 0; i < strlen(c); ++i)
	{
		if (isdigit(c[i]) || ((c[i] == '+' || c[i] == '-') && (i == 0 || c[i - 1] == '(')))
		{
			if (c[i] != '+')
				end += c[i];
			i++;
			while ((i < strlen(c) && isdigit(c[i])) || c[i] == '.')
			{
				end += c[i];
				i++;
			}
			i--;
			end += ' ';
		}
		else //如果是字符
		{
			if (s.empty() || c[i] == '(')
				s.push(c[i]);
			else
			{
				if (c[i] == ')')
				{
					while (!s.empty() && s.top() != '(')
					{
						end += s.top();
						end += ' ';
						s.pop();
					}
					s.pop(); //左括号出栈
				}
				else
				{
					if (cmp(s.top(), c[i]))
					{
						while (!s.empty() && cmp(s.top(), c[i]))
						{
							end += s.top();
							end += ' ';
							s.pop();
						}
						s.push(c[i]);
					}
					else
					{
						s.push(c[i]);
					}
				}
			}
		}
	}
	while (!s.empty())
	{
		end += s.top();
		end += ' ';
		s.pop();
	}
	for (int i = 0; i < end.size() - 1; ++i)
	{
		if (end[i] == '-' || isdigit(end[i]))
		{
			if (end[i] == '-')
				i++;
			double num = end[i] - '0';
			for (++i; i < end.size() - 1; ++i)
			{
				if (isdigit(end[i]))
				{
					num = num * 10 + (end[i] - '0');
				}
				else
					break;
			}
			if (end[i] == '-')
				num = -num;
			q.push(num);
		}
		else if (end[i] != ' ')
		{
			double aa = q.top();
			q.pop();
			double bb = q.top();
			q.pop();
			switch (end[i])
			{
			case '+':
				q.push(aa + bb);
				break;
			case '-':
				q.push(aa - bb);
				break;
			case '*':
				q.push(aa * bb);
				break;
			case '/':
			{
				if (bb == 0)
				{
					cout << c << " = NAN" << endl;
				}
				q.push(aa / bb);
				break;
			}
			}
		}
	}
	cout << c << " = " << q.top() << endl;
	return 0;
}