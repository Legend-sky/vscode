/*
 * @Autor: Whx
 * @Date: 2020-11-07 09:59:27
 * @LastEditTime: 2020-11-07 10:28:40
 */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int top = 0;
char pre[55], in[55];
struct node
{
    char num;
    struct node *left;
    struct node *right;
} node;
struct node *dfs(char pre[], char in[], int n)
{
    int num = 0;
    char root = '0';
    if (n == 0)
        return NULL;
    struct node *T;
    T = (struct node *)malloc(sizeof(struct node));
    if (T == NULL)
        return NULL;
    root = pre[0];
    T->num = root;
    for (int i = 0; i < n; i++)
    {
        if (root == in[i])
        {
            num = i;
            break;
        }
    }
    T->left = dfs(pre + 1, in, num);
    T->right = dfs(pre + num + 1, in + num + 1, n - num - 1);
    return T;
}
int depth(struct node *T)
{
    if (T == NULL)
        return 0;
    else
        return max(depth(T->left) + 1, depth(T->right) + 1);
}
int main()
{
    int n;
    cin >> n;
    struct node *BT = NULL;
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    BT = dfs(pre, in, n);
    cout << depth(BT);
    return 0;
}