//
// Created by Mocshere on 2023-08-23.
//
#include <iostream>
using namespace std;
struct TreeNode
{
    char val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* build_tree();

// 分支节点都是运算符节点，叶子节点都是值节点
void get_infix_ex(TreeNode* root, int depth)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->val;
    }
    else
    {
        // 除了根节点外，每个分支节点都要加括号
        if (depth > 0)
        {
            cout << "(";
        }
        get_infix_ex(root->left, depth + 1);
        cout << root->val;
        get_infix_ex(root->right, depth + 1);
        if (depth > 0)
        {
            cout << ")";
        }
    }
}

// * + a # # b # # * c # # - # d # #
int main()
{
    cout << "Please input the values of per node: " << endl;
    TreeNode *root = build_tree();
    get_infix_ex(root, 0);
    return 0;
}

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