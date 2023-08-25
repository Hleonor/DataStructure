//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

int cal_double_children(TreeNode *root)
{
    queue<TreeNode*> myQueue;
    int cnt = 0;
    if (root)
    {
        myQueue.push(root);
        while (!myQueue.empty())
        {
            TreeNode* node = myQueue.front();
            if (node->left)
            {
                myQueue.push(node->left);
            }
            if (node->right)
            {
                myQueue.push(node->right);
                cnt++;
            }
            myQueue.pop();
            delete node;
        }
        return cnt;
    }
    return 0;
}

int main()
{
    TreeNode* root = build_tree();
    cout << cal_double_children(root) << endl;
    return 0;
}