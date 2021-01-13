/*
 * @Author: Whx
 * @Date: 2021-01-13 10:42:51
 * @LastEditTime: 2021-01-13 10:51:20
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int main()
{
    string n, res;
    int k, m;
    cin >> n >> k;
    m = n.length() - k;
    for (char c : n)
    {
        while (k && res.size() && c < res.back())
        {
            res.pop_back();
            k--;
        }
        res.push_back(c);
    }
    res.resize(m); //假设为123456 3，那么上面的循环未已取任何数，就取前三个数123
    while (!res.empty() && res[0] == '0')
    {
        res.erase(res.begin());
    }
    if (res.empty())
        cout << "0";
    else
        cout << res;
    return 0;
}
