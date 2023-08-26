//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"
#include <stack>

// 有一说一真的不好写，想了很久主要的问题不是先左后右，而是应该处理好右节点的重复访问导致的循环迭代的问题
int main()
{
    TreeNode* root = build_tree();
    stack<TreeNode*> myStack;
    TreeNode* cur = root;
    TreeNode* tmp_right = nullptr;
    while (true)
    {
        if (cur == nullptr && myStack.empty())
        {
            break;
        }

        while (cur)
        {
            myStack.push(cur);
            cur = cur->left;
        }

        if (myStack.top()->right && myStack.top()->right != tmp_right) // 如果当前节点的右节点等于刚刚弹栈的节点
        {
            cur = myStack.top()->right;
        }
        else
        {
            cout << myStack.top()->val << " ";
            tmp_right = myStack.top(); // 记录刚刚弹出的栈顶元素
            myStack.pop();
        }
    }
}