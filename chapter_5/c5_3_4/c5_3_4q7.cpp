//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
bool isComplete(TreeNode *root)
{
    queue<TreeNode*> queue_1;
    queue<TreeNode*> queue_2;
    bool flag = false;
    if (root == nullptr)
    {
        return true;
    }
    else
    {
        queue_1.push(root); // 遍历用
        queue_2.push(root); // 判断用
        while (!queue_1.empty())
        {
            TreeNode* node = queue_1.front();
            queue_2.push(node->left);
            queue_2.push(node->right);
            if (node->left)
            {
                queue_1.push(node->left);
            }
            if (node->right)
            {
                queue_1.push(node->right);
            }
            queue_1.pop();
        }
        while (true)
        {
            TreeNode* node = queue_2.front();
            if (node == nullptr)
            {
                queue_2.pop();
                while (!queue_2.empty())
                {
                    if (queue_2.front())
                    {
                        return false;
                    }
                    queue_2.pop();
                }
                return true;
            }
            queue_2.pop();
        }
        return true;
    }
}

int main()
{
    TreeNode* root = build_tree();
    cout << isComplete(root) << endl;
    return 0;
}