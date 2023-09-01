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

void build_brothers(TreeNode* node, string sequence, int edgeNum)
{

}

TreeNode* build_tree(string sequence, vector<int> edgeNum)
{
    TreeNode* root = nullptr;
    TreeNode* cur = root;
    int pos = 0; // 指向最左边的还没使用过的节点
    int i = 0; // 用来访问edgeNum
    while (pos != sequence.size())
    {
        cur = new TreeNode;
        cur->val = sequence[pos];
        if (edgeNum[i] >= 1) // 说明至少有一个孩子的情况
        {
            TreeNode* tmp = new TreeNode;
            pos++;
            tmp->val = sequence[pos];
            cur->left = tmp;
            edgeNum[i]--;
            if (edgeNum[i] >= 1) // 说明tmp至少有一个兄弟，则构建兄弟
            {
                build_brothers(tmp, sequence.substr(pos, edgeNum[i]), edgeNum[i]);
            }
            pos += edgeNum[i];
            cur = cur->left;
            i++;
        }
        else
        {
            delete cur;

        }
    }

    return root;
}

// G H K # L # # I # J M P # # N # O # # # #
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


    return 0;
}