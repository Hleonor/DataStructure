//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

// 思路：分两种情况
// 1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 10 -1 -1 11 -1 -1 7 -1 -1
stack<TreeNode *> construct_ancestor_stack(TreeNode *root, int val);
void public_ancestor(TreeNode *root, int node_1, int node_2)
{
    stack<TreeNode*> stack1 = construct_ancestor_stack(root, node_1);
    stack<TreeNode*> stack2 = construct_ancestor_stack(root, node_2);
    if (stack1.empty() || stack2.empty())
    {
        cout << "Can't find node with value node_1 or node_2." << endl;
        return;
    }
    while (stack1.size() > stack2.size())
    {
        stack1.pop();
    }
    while (stack2.size() > stack1.size())
    {
        stack2.pop();
    }

    while (stack1.top() != stack2.top())
    {
        stack1.pop();
        stack2.pop();
    }
    cout << "Nearest public ancestor is: " << stack1.top()->val;
}

stack<TreeNode *> construct_ancestor_stack(TreeNode *root, int val)
{
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
            if (cur->val == val)
            {
                return myStack;
            }
            myStack.push(cur);
            cur = cur->left;
        }

        if (myStack.top()->right && myStack.top()->right != tmp_right) // 如果当前节点的右节点等于刚刚弹栈的节点
        {
            cur = myStack.top()->right;
        }
        else
        {
            tmp_right = myStack.top(); // 记录刚刚弹出的栈顶元素
            myStack.pop();
        }
    }
    return myStack;
}


int main()
{
    cout << "Please input the values of per node: " << endl;
    TreeNode *root = build_tree();
    int node_1 = -1;
    int node_2 = -1;
    cout << "Please input value of node_1: ";
    cin >> node_1;
    cout << "Please input value of node_2: ";
    cin >> node_2;
    cout << endl;
    public_ancestor(root, node_1, node_2);
    return 0;
}