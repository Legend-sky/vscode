#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int val, l, r;
} node[50];
int top = 0, post[50], in[50];
int dfs(int post[], int in[], int len)
{
    if (len <= 0)
        return -1;
    if (len == 1)
    {
        node[++top].val = in[1];
        node[top].l = node[top].r = -1;
        return top;
    }
    node[++top].val = post[len];
    int res = top;
    int i;
    for (i = 1; i <= len; i++)
    {
        if (in[i] == post[len])
            break;
    }
    node[res].l = dfs(post, in, i - 1);
    node[res].r = dfs(post + i - 1, in + i, len - i);
    return res;
}
void bfs()
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur != 1)
            cout << " ";
        cout << node[cur].val;
        if (node[cur].l != -1)
            q.push(node[cur].l);
        if (node[cur].r != -1)
            q.push(node[cur].r);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> post[i];
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    dfs(post, in, n);
    bfs();
    return 0;
}