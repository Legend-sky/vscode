/*
 * @Author: Whx
 * @Date: 2020-11-29 21:41:22
 * @LastEditTime: 2020-11-29 22:02:19
 */
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string, int> list;
int main()
{
    string s, s1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> s1;
        list[s]++;
        list[s1]++;
    }
    string ans;
    int res = 0;
    int bin = 0;
    for (map<string, int>::iterator it = list.begin(); it != list.end(); it++)
    {
        if (it->second > res)
        {
            res = it->second;
            ans = it->first;
        }
    }
    for (map<string, int>::iterator it = list.begin(); it != list.end(); it++)
        if (it->second == res)
            bin++;
    cout << ans << " " << res;
    if (bin > 1)
        cout << " " << bin;
}