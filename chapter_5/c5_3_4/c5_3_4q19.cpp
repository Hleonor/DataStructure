//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

int totalWPL = 0;
void calWPL(TreeNode* root, int depth)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        totalWPL += root->val * depth;
    }
    else
    {
        calWPL(root->left, depth + 1);
        calWPL(root->right, depth + 1);
    }
}

int main()
{
    cout << "Please input the values of per node: " << endl;
    TreeNode *root = build_tree();
    calWPL(root, 1);
    cout << totalWPL << endl;
    return 0;
}