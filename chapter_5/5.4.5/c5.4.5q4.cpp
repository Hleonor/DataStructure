//
// Created by Mocshere on 2023-08-30.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    char val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* build_tree()
{
    char data = '#';
    cin >> data;
    if (data == '#')
    {
        return nullptr;
    }

    auto* new_node = new TreeNode;
    new_node->val = data;
    new_node->left = build_tree();
    new_node->right = build_tree();

    return new_node;
}

queue<TreeNode*> binaryTree_to_forest(TreeNode* root)
{
    TreeNode* cur = root;
    queue<TreeNode*> result;
    while (cur)
    {
        result.push(cur);
        TreeNode* tmp = cur->right;
        cur->right = nullptr;
        cur = tmp;
    }
    return result;
}

// 采用层次遍历，之要没有左孩子的都是叶子节点
int cal_leaves(queue<TreeNode*> forest)
{
    int result = 0;
    while (!forest.empty())
    {
        queue<TreeNode*> tmpQueue;
        TreeNode* root = forest.front();
        if (root)
        {
            tmpQueue.push(root);
            while (!tmpQueue.empty())
            {
                TreeNode* node = tmpQueue.front();
                tmpQueue.pop();
                if (node->left == nullptr)
                {
                    result++;
                }
                if (node->left)
                {
                    tmpQueue.push(node->left);
                }
                if (node->right)
                {
                    tmpQueue.push(node->right);
                }
            }
        }
        forest.pop();
    }
    return result;
}

// A B D # # E H # # # C F I # M # # # G # J K # L # # #
int main()
{
    cout << "Please input the values of per node: " << endl;
    TreeNode *root = build_tree();
    queue<TreeNode*> transfer = binaryTree_to_forest(root);
    cout << "The number of leaves is: " << cal_leaves(transfer) << endl;
    return 0;
}