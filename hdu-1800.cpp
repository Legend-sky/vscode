/*
 * @Author: Whx
 * @Date: 2021-01-11 21:39:17
 * @LastEditTime: 2021-01-11 22:36:14
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
using namespace std;
map<int, int> m;
int main()
{
    //ios::sync_with_stdio(false);
    int n, t;
    while (scanf("%d", &n) != EOF)
    {
        m.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &t);
            m[t]++;
        }
        int res = 0;
        map<int, int>::iterator it = m.begin();
        for (; it != m.end(); it++)
        {
            if ((*it).second > res)
                res = (*it).second;
        }
        printf("%d\n", res);
    }
    return 0;
}