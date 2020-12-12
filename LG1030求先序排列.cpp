/*
 * @Author: Whx
 * @Date: 2020-11-06 21:32:56
 * @LastEditTime: 2020-12-05 23:08:57
 */
#include <bits/stdc++.h>
using namespace std;
int len;
string mid, last;
void dfs(int l1, int r1, int l2, int r2)
{
    if (l1 > r1 || l2 > r2)
        return;
    printf("%c", last[r2]);
    for (int i = l1; i <= r1; i++)
    {
        if (last[r2] == mid[i])
        {
            dfs(l1, i - 1, l2, l2 + i - l1 - 1); //后序的长度与中序的左子树长度相等
            dfs(i + 1, r1, l2 + i - l1, r2 - 1);
        }
    }
}
int main()
{
    mid.resize(50);
    last.resize(50);
    scanf("%s\n", &mid[0]);
    scanf("%s", &last[0]);
    len = strlen(&mid[0]);
    dfs(0, len - 1, 0, len - 1);
    return 0;
}