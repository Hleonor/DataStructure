//
// Created by Mocshere on 2023-08-22.
//
#include "chapter5_header.h"

int main()
{
    TreeNode* root = build_tree();
    pre_traversal(root);
    cout << endl;
    middle_traversal(root);
    cout << endl;
    behind_traversal(root);
    cout << endl;
    hierarchicalTraversal(root);
    cout << endl;
    return 0;
}