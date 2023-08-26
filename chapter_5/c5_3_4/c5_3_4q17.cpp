//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

// 对应位置有节点就是相似的，不管是左孩子还是右孩子
bool isSimilar(TreeNode *root_1, TreeNode *root_2)
{
    if (root_1 == nullptr && root_2 == nullptr)
    {
        return true;
    }
    else if (root_1 == nullptr || root_2 == nullptr)
    {
        return false;
    }
    else
    {
        return isSimilar(root_1->left, root_2->left) && isSimilar(root_1->right, root_2->right);
    }
}


int main()
{
    cout << "Please input the values of per node: " << endl;
    TreeNode *root = build_tree();

    return 0;
}