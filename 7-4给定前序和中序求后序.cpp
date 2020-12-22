/*
 * @Author: Whx
 * @Date: 2020-12-22 19:05:46
 * @LastEditTime: 2020-12-22 19:27:14
 */
#include <iostream>
using namespace std;
#include <string>

struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    char elem;
};

TreeNode *postorder(char pre[], char in[], int n1)
{
    if (n1 == 0)
    {
        return NULL;
    }
    TreeNode *node = new TreeNode;
    node->elem = *pre;
    int rootIndex = 0;
    for (; rootIndex < n1; rootIndex++)
    {
        if (in[rootIndex] == *pre)
            break;
    }
    node->left = postorder(pre + 1, in, rootIndex);
    node->right = postorder(pre + rootIndex + 1, in + rootIndex + 1, n1 - (rootIndex + 1));
    cout << node->elem;
    return node;
}
int main()
{
    char pre[40], in[40];
    cin >> pre;
    cin >> in;
    int n;
    for (n = 0; pre[n] != '\0'; n++)
        ;
    postorder(pre, in, n);
    return 0;
}