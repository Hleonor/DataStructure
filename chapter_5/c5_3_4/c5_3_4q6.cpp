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

TreeNode* build_tree(const string& pre, const string& middle)
{
    TreeNode* root = new TreeNode;
    root->val = pre[0];
    int pos = middle.find(pre[0]);

}

int main()
{
    string pre;
    string middle;
    cin >> pre;
    cin >> middle;
    TreeNode *root = build_tree(pre, middle);
    return 0;
}