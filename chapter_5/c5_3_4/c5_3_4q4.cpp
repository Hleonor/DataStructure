//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

int main()
{
    TreeNode* root = build_tree();
    stack<int> myStack;
    queue<TreeNode*> myQueue;
    if (root)
    {
        myQueue.push(root);
        while (!myQueue.empty())
        {
            TreeNode* node = myQueue.front();
            myStack.push(node->val);

            myQueue.pop();
            if (node->left)
            {
                myQueue.push(node->left);
            }
            if (node->right)
            {
                myQueue.push(node->right);
            }
            delete node;
        }
        while (!myStack.empty())
        {
            cout << myStack.top() << " ";
            myStack.pop();
        }
    }
    return 0;
}