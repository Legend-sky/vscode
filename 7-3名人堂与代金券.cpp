/*
 * @Author: Whx
 * @Date: 2021-01-09 21:57:34
 * @LastEditTime: 2021-01-09 22:29:43
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;
struct stu
{
    string name;
    int score;
    int mc;
} a[10005];
bool cmp(struct stu a, struct stu b)
{
    if (a.score == b.score)
        return a.name < b.name;
    else
        return a.score > b.score;
}
int main()
{
    int n, g, k;
    int sum = 0;
    cin >> n >> g >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].score;
        if (a[i].score >= g)
            sum += 50;
        else if (a[i].score >= 60 && a[i].score < g)
            sum += 20;
    }
    cout << sum << endl;
    sort(a, a + n, cmp);
    int p = 1;
    a[0].mc = 1;
    p++;
    for (int i = 1; i < n; i++, p++)
    {
        if (a[i].score == a[i - 1].score)
        {
            a[i].mc = a[i - 1].mc;
        }
        else
        {
            a[i].mc = p;
        }
    }
    for (int i = 0; a[i].mc <= k && i < n; i++)
    {
        cout << a[i].mc << " " << a[i].name << " " << a[i].score << endl;
    }
    return 0;
}