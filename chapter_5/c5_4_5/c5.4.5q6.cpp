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


TreeNode* build_tree(string sequence, vector<int> edgeNum)
{
    TreeNode* root = nullptr;
    vector<TreeNode*> tree_nodes;
    for (int i = 0; i < sequence.size(); i++)
    {
        TreeNode* tmp = new TreeNode;
        tmp->val = sequence[i];
        tmp->left = nullptr;
        tmp->right = nullptr;
        tree_nodes.push_back(tmp);
    }
    int pos = 0;
    for (int i = 0; i < sequence.size(); i++)
    {
        int degree = edgeNum[i];
        if (degree)
        {
            pos++;
            tree_nodes[i]->left = tree_nodes[pos];
            for (int j = 2; j <= degree; j++)
            {
                pos++;
                tree_nodes[pos - 1]->right = tree_nodes[pos];
            }
        }
    }
    if (!tree_nodes.empty())
    {
        root = tree_nodes[0];
    }
    return root;
}

// G H K # L # # I # J M P # # N # O # # # #
// GHIJKLMNOP
// 3 2 0 3 0 0 1 0 0 0
int main()
{
    string sequence;
    cout << "Input the hierarchical traversal sequence: " << endl;
    cin >> sequence;

    vector<int> edgeNum;
    cout << "Input the edge number of per node:" << endl;
    for (int i = 0; i < sequence.size(); i++)
    {
        int num = 0;
        cin >> num;
        edgeNum.push_back(num);
    }

    TreeNode* root = build_tree(sequence, edgeNum);
    // 打印树
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

    return 0;
}