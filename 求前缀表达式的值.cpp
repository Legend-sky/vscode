/*
 * @Autor: Whx
 * @Date: 2020-10-23 09:13:28
 * @LastEditTime: 2020-10-23 21:26:24
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
stack<double> q;
int main()
{
    string a;
    getline(cin, a);
    for (int i = a.length() - 1; i >= 0; --i)
    {
        if (isdigit(a[i]))
        {
            double mul = 10, num = a[i] - '0';
            for (--i; i >= 0; --i)
            {
                if (isdigit(a[i]))
                {
                    num += (a[i] - '0') * mul;
                    mul *= 10;
                }
                else if (a[i] == '.')
                {
                    num /= mul;
                    mul = 1;
                }
                else if (a[i] == '-')
                    num = -num;
                else
                    break;
            }
            q.push(num);
        }
        else if (a[i] != ' ')
        {
            double aa = q.top();
            q.pop();
            double bb = q.top();
            q.pop();
            switch (a[i])
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
                    cout << "ERROR";
                    return 0;
                }
                q.push(aa / bb);
            }
            }
        }
    }
    cout << fixed << setprecision(1);
    cout << q.top();
}