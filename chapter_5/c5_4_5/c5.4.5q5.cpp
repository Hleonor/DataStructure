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

int depth = INT_MIN;
void cal_depth(TreeNode* root, int deep)
{
    if (root)
    {
        if (deep > depth)
        {
            depth = deep;
        }
        cal_depth(root->left, deep + 1);
        cal_depth(root->right, deep);
    }
}



// G H K # L # # I # J M P # # N # O # # # #
int main()
{
    cout << "Please input the values of per node: " << endl;
    TreeNode *root = build_tree();
    cal_depth(root, 1);
    cout << depth << endl;
    return 0;
}