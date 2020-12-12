/*
 * @Author: Whx
 * @Date: 2020-11-17 20:11:59
 * @LastEditTime: 2020-11-17 20:33:28
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int n, m, len = 0, a;
int y;
string s1, s2, s3, s4, s5, s6, s7, s8;
int h[1005];
void push(int x)
{
    int i = ++len;
    while (h[i / 2] > x && i > 1)
    {
        h[i] = h[i / 2];
        i /= 2;
    }
    h[i] = x;
}
int find(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (h[i] == k)
            return i;
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        push(a);
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        cin >> s1;
        if (s1 == "is")
        {
            cin >> s2;
            if (s2 == "the")
            {
                cin >> s3;
                if (s3 == "root")
                {
                    if (h[1] == x)
                        cout << 'T' << endl;
                    else
                        cout << 'F' << endl;
                }
                else
                {
                    cin >> s4 >> y;
                    if (find(x) == find(y) / 2)
                        cout << 'T' << endl;
                    else
                        cout << 'F' << endl;
                }
            }
            else if (s2 == "a")
            {
                cin >> s5 >> s6 >> y;
                if (find(x) / 2 == find(y))
                    cout << 'T' << endl;
                else
                    cout << 'F' << endl;
            }
        }
        else if (s1 == "and")
        {
            cin >> y >> s7 >> s8;
            if (find(x) / 2 == find(y) / 2)
                cout << 'T' << endl;
            else
                cout << 'F' << endl;
        }
    }
    return 0;
}