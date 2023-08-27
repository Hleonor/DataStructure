//
// Created by Mocshere on 2023-08-23.
//
#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 20

struct Tree
{
    int SqBiTNode[MAX_SIZE];
    int ElemNum = 0;
};

Tree* build_tree(const vector<int>& ele)
{
    Tree* root = new Tree;
    root->SqBiTNode[0] = -1;
    // 初始化所有元素为-1
    for (int i = 1; i < MAX_SIZE; i++)
    {
        root->SqBiTNode[i] = -1;
    }
    for (int i = 0; i < ele.size(); i++)
    {
        root->SqBiTNode[i + 1] = ele[i];
        root->ElemNum++;
    }
    return root;
}

bool isSearchTree(Tree* root)
{
    bool flag = true;
    for (int i = 1; i <= root->ElemNum; i++)
    {
        if (root->SqBiTNode[i] != -1 && root->SqBiTNode[i * 2] != -1 && root->SqBiTNode[i * 2 + 1] != -1)
        {
            if (root->SqBiTNode[i * 2] > root->SqBiTNode[i] || root->SqBiTNode[i * 2 + 1] < root->SqBiTNode[i])
            {
                flag = false;
            }
        }
    }
    return flag;
}

int main()
{
    cout << "Please input the values of per node: " << endl;
    vector<int> ele = {40, 25, 60, -1, 30, -1, 80, -1, -1, 27};
    vector<int> ele1 = {40, 50, 60, -1, 30, -1, -1, -1, -1, -1, 35};
    Tree* root = build_tree(ele1);
    cout << isSearchTree(root) << endl;
    return 0;
}

