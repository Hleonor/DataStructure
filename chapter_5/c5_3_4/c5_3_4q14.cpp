//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

// 1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 12 -1 -1 13 -1 -1 7 14 -1 -1 15 -1 -1
int cal_width(TreeNode *root)
{
    queue<TreeNode*> myQueue;
    TreeNode* right = nullptr;
    int max_node_num = INT_MIN;
    int cnt = 0;
    if (root)
    {
        myQueue.push(root);
        right = root;
        while (!myQueue.empty())
        {
            // 先入队再出队
            TreeNode* node = myQueue.front();
            cnt++;
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
                if (cnt >= max_node_num)
                {
                    max_node_num = cnt;
                    cnt = 0;
                }
                right = node->right;
            }
            myQueue.pop();
        }
    }
    return max_node_num;
}
int main()
{
    cout << "Please input the values of per node: " << endl;
    TreeNode *root = build_tree();
    cout << cal_width(root) << endl;
    return 0;
}