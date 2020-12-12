/*
 * @Author: Whx
 * @Date: 2020-11-19 22:59:19
 * @LastEditTime: 2020-11-20 20:41:44
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int n, tmp;
string s, s1;
map<int, string> m;
map<int, string>::iterator it;
int main()
{
    s.resize(100);
    s1.resize(100);
    cin >> n;
    while (n--)
    {
        scanf("%s", &s[0]);
        if (s[0] == 'P')
        {
            scanf("%s", &s[0]);
            scanf("%d", &tmp);
            m.insert(pair<int, string>(tmp, s));
        }
        else
        {
            if (m.size() == 0)
                printf("EMPTY QUEUE!\n");
            else
            {
                it = m.begin();
                printf("%s\n", it->second.c_str());
                m.erase(it->first);
            }
        }
    }
    return 0;
}