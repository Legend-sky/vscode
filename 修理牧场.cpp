/*
 * @Author: Whx
 * @Date: 2020-11-20 19:03:29
 * @LastEditTime: 2020-11-20 20:13:35
 */
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, a;
multiset<int> m;
int main()
{
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        m.insert(a);
    }
    while (!m.empty())
    {
        int x = *m.begin();
        m.erase(m.begin());
        if (m.empty())
            break;
        int y = *m.begin();
        m.erase(m.begin());
        x += y;
        sum += x;
        m.insert(x);
    }
    cout << sum;
}