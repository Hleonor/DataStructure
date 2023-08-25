//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

TreeNode* node = nullptr;
int cnt = 0;
void find_k(TreeNode* root,int k)
{
    if (root)
    {
        cnt++;
        if (cnt == k)
        {
            node = root;
            return ;
        }
        else
        {
            find_k(root->left, k);
            find_k(root->left, k);
        }
    }
}

int main()
{
    TreeNode* root = build_tree();
    int k = 0;
    find_k(root, k);
    if (node)
    {
        cout << node->val << endl;
    }
    else
    {
        cout << "Not found k." << endl;
    }
    return 0;
}