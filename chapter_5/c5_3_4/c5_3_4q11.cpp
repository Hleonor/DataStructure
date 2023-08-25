//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

// 要特别注意，传参的问题，这里反复出现问题，就是因为只是将参数的root设置为了nullptr，而不是真正把原来的树中的指针设置为了空
void delete_x(TreeNode*& root, int x)
{
    if (root)
    {
        if (root->val == x)
        {
            delete_tree(root);
            root = nullptr;
            return;
        }
        if (root->left)
        {
            delete_x(root->left, x);
            if (root->left->val == x)
            {
                delete_tree(root->left);
                root->left = nullptr;
            }
            else
            {
                delete_x(root->left, x);
            }
        }
        if (root->right)
        {
            if (root->right->val == x)
            {
                delete_tree(root->right);
                root->right = nullptr;
            }
            else
            {
                delete_x(root->right, x);
            }
        }
    }
}

int main()
{
    TreeNode* root = build_tree();
    delete_x(root, 1);
    hierarchicalTraversal(root);
    return 0;
}