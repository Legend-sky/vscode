/*
 * @Author: Whx
 * @Date: 2020-12-22 18:35:35
 * @LastEditTime: 2020-12-22 18:50:48
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
string s;
stack<char> p;
char t;
int main()
{
    cin >> s;
    bool f = true;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '[')
            p.push(s[i]);
        if (s[i] == '(')
            p.push(s[i]);
        if (s[i] == ']')
        {
            if (p.empty())
            {
                f = false;
                break;
            }
            t = p.top();
            p.pop();
            if (t != '[')
            {
                f = false;
                break;
            }
        }
        if (s[i] == ')')
        {
            if (p.empty())
            {
                f = false;
                break;
            }
            t = p.top();
            p.pop();
            if (t != '(')
            {
                f = false;
                break;
            }
        }
    }
    if (f && p.empty())
        cout << "T";
    else
        cout << "F";
    return 0;
}