//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

TreeNode* build_list_by_leaves(TreeNode* root)
{
    TreeNode* head = new TreeNode;
    head->val = -1;
    head->left = nullptr;
    head->right = nullptr;
    TreeNode* pre = head;
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
            tmp_right = myStack.top(); // 记录刚刚弹出的栈顶元素
            if (tmp_right->left == nullptr && tmp_right->right == nullptr) // 说明是叶子
            {
                pre->right = tmp_right;
                pre = tmp_right;
            }
            myStack.pop();
        }
    }
    return head;
}

int main()
{
    cout << "Please input the values of per node: " << endl;
    TreeNode *root = build_tree();
    TreeNode *head = build_list_by_leaves(root);
    // 打印head链表
    TreeNode *cur = head->right;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->right;
    }
    return 0;
}