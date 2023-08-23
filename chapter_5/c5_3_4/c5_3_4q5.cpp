//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"
#include <math.h>

// 直接利用公式，通过层序遍历知道节点总数n以后，利用公式log2n + 1
int main()
{
    TreeNode* root = build_tree();
    queue<TreeNode*> myQueue;
    TreeNode* right = nullptr;
    int level = 0;
    if (root)
    {
        myQueue.push(root);
        right = root;
        while (!myQueue.empty())
        {
            // 先入队再出队
            TreeNode* node = myQueue.front();
            if (node->left)
            {
                myQueue.push(node->left);
            }
            if (node->right)
            {
                myQueue.push(node->right);
            }
            if (node == right)
            {
                level++;
                right = node->right;
            }
            myQueue.pop();
        }
    }

    cout << "The height of tree is: "  << level << endl;
    return 0;
}