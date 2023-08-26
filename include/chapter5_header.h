//
// Created by Hleonor on 2023-08-20.
//

#ifndef DATASTRUCTURE_CHAPTER5_HEADER_H
#define DATASTRUCTURE_CHAPTER5_HEADER_H
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct ThreadTreeNode
{
    int val;
    ThreadTreeNode* left;
    ThreadTreeNode* right;
    bool ltag;
    bool rtag;
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* build_tree()
{
    int data = -1;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }

    auto* new_node = new TreeNode;
    new_node->val = data;
    new_node->left = build_tree();
    new_node->right = build_tree();

    return new_node;
}

void pre_traversal(TreeNode* node)
{
    if (node)
    {
        cout << node->val << " ";
        pre_traversal(node->left);
        pre_traversal(node->right);
    }
}

void middle_traversal(TreeNode* node)
{
    if (node)
    {
        middle_traversal(node->left);
        cout << node->val << " ";
        middle_traversal(node->right);
    }
}

void behind_traversal(TreeNode* node)
{
    if (node)
    {
        behind_traversal(node->left);
        behind_traversal(node->right);
        cout << node->val << " ";
    }
}

void hierarchicalTraversal(TreeNode* root)
{
    queue<TreeNode*> queue;
    if (root)
    {
        queue.push(root);
        while (!queue.empty())
        {
            TreeNode* node = queue.front();
            queue.pop();
            cout << node->val << " ";
            if (node->left)
            {
                queue.push(node->left);
            }
            if (node->right)
            {
                queue.push(node->right);
            }
        }
    }
}

void delete_tree(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr) // 叶子节点直接删除
    {
        delete root;
        root = nullptr;
    }
    else
    {
        if (root->left) // 如果有左子树
        {
            delete_tree(root->left);
            root->left = nullptr;
        }
        if (root->right)
        {
            delete_tree(root->right);
            root->right = nullptr;
        }
        delete root;
        root = nullptr;
    }
}

/*=================================================线索二叉树相关函数=================================================*/

void inThread(ThreadTreeNode* cur, ThreadTreeNode*& pre)
{
    if (cur) // 如果当前节点不为空
    {
        inThread(cur->left, pre);
        if (cur->left == nullptr) // 没有左孩子，此时进行线索化
        {
            cur->left = pre;
            cur->ltag = true;
        }
        if (pre && pre->right == nullptr)
        {
            pre->right = cur;
            pre->rtag = true;
        }
        pre = cur;
        inThread(cur->right, pre);
    }
}

ThreadTreeNode* createInThread()
{
    // 先根据先序遍历创建一颗二叉树
    ThreadTreeNode* root = nullptr;
    int data = -1;
    cin >> data;
    if (data != -1)
    {
        root = new ThreadTreeNode;
        root->val = data;
        root->ltag = false;
        root->rtag = false;
        root->left = createInThread();
        root->right = createInThread();
    }
    return root;
}

ThreadTreeNode* create_thread_tree_main()
{
    ThreadTreeNode* root = createInThread();
    ThreadTreeNode* pre = nullptr;
    if (root)
    {
        inThread(root, pre);
        pre->right = nullptr; // 当inThread函数调用完成以后，pre的right指针就指向了中序遍历的最后一个节点
        pre->rtag = true; // 因为最后一个节点必然没有右孩子，所以rtag就设置成1表示后继
    }
    return root;
}

ThreadTreeNode* first_node(ThreadTreeNode* cur) // 求的是以cur为根节点的子树中序遍历的第一个节点
{
    while (cur->ltag == false) // 当节点的左标记为假时，说明有左孩子，则一直往左下寻找
    {
        cur = cur->left;
    }
    return cur; // 退出循环的时候，即cur->ltag == 1，说明
}

ThreadTreeNode* next_node(ThreadTreeNode* cur)
{
    if (cur->rtag == false) // 说明右孩子存在
    {
        // 去右子树中寻找第一个节点
        return first_node(cur->right);
    }
    else // 右孩子不存在的时候，此时后继就是线索
    {
        return cur->right;
    }
}

void inOrder(ThreadTreeNode* root)
{
    for (ThreadTreeNode* node = first_node(root); node != nullptr; node = next_node(node))
    {
        cout << node->val << " ";
    }
}

#endif //DATASTRUCTURE_CHAPTER5_HEADER_H
