//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

void switch_left_right(TreeNode* root)
{
    if (root)
    {
        TreeNode* tmp_left  = root->left;
        TreeNode* tmp_right = root->right;
        root->left = tmp_right;
        root->right = tmp_left;
        switch_left_right(root->left);
        switch_left_right(root->right);
    }
    else
    {
        return;
    }
}

int main()
{
    TreeNode* root = build_tree();
    switch_left_right(root);
    hierarchicalTraversal(root);
    return 0;
}