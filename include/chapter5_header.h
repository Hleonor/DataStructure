//
// Created by Hleonor on 2023-08-20.
//

#ifndef DATASTRUCTURE_CHAPTER5_HEADER_H
#define DATASTRUCTURE_CHAPTER5_HEADER_H
#include <iostream>
#include <queue>

using namespace std;

struct ThreadTreeNode
{
    int val;
    ThreadTreeNode* left;
    ThreadTreeNode* right;
    bool left_thread;
    bool right_thread;
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
            delete node;
        }
    }
}

#endif //DATASTRUCTURE_CHAPTER5_HEADER_H
