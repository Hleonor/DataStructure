//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"
#include <math.h>

// 直接利用公式，通过层序遍历知道节点总数n以后，利用公式log2n + 1
int main()
{
    TreeNode* root = build_tree();
    int nodeNum = 0;
    queue<TreeNode*> queue;
    if (root)
    {
        queue.push(root);
        while (!queue.empty())
        {
            TreeNode* node = queue.front();
            queue.pop();
            nodeNum++;
            if (node->left)
            {
                queue.push(node->left);
            }
            if (node->right)
            {
                queue.push(node->right);
            }
            delete node;
        }
    }
    cout << "The height of tree is: " << (int)log2(nodeNum) + 1 << endl;
    return 0;
}