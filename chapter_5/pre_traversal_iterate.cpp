//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"
#include <stack>

int main()
{
    TreeNode* root = build_tree();
    stack<TreeNode*> myStack;
    TreeNode* cur = root;
    while (cur || !myStack.empty())
    {
        if (cur)
        {
            cout << cur->val << " ";
            myStack.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = myStack.top()->right;
            myStack.pop();
        }
    }
}