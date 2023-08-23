//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"
#include <stack>

// 1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 -1 7 -1 -1
// 1 2 4 8 12 13 -1 -1 -1 -1 9 -1 -1 5 -1 -1 3 6 10 -1 -1 11 -1 -1 7 -1 -1
int main()
{
    TreeNode* root = build_tree();
    TreeNode* cur_node = root;
    stack<TreeNode*> myStack;
    while (cur_node || !myStack.empty())
    {
        if (cur_node)
        {
            myStack.push(cur_node);
            cur_node = cur_node->left;
        }
        else
        {
            cout << myStack.top()->val << " ";
            cur_node = myStack.top()->right;
            myStack.pop();
        }
    }
}