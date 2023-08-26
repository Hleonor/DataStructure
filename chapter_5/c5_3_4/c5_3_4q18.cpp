//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

// 如果该节点有右孩子，则后序前驱就是右孩子
// 如果该节点只有左孩子，则后序前驱就是左孩子
// 如果该节点是一个叶子节点，就需要一直向上寻找到一个有左孩子的子树根节点，此时该根节点的左孩子就是当前叶子的前驱
int find_post_in_middle_tread_tree(ThreadTreeNode* root, int k)
{
    ThreadTreeNode* node = nullptr;
    // 先找到节点k
    for (node = first_node(root); node != nullptr; node = next_node(node))
    {
        if (node->val == k)
        {
            break;
        }
    }
    // 判断节点k的类型
    if (!node->rtag) // 有右孩子
    {
        return node->right->val;
    }
    else if (!node->ltag)
    {
        return node->left->val;
    }
    else if (node->left == nullptr) // 因为线索化过了，所以左孩子要么是真的孩子，要么是左线索
    {
        return -1;
    }
    else // 说明是叶子节点
    {
        while (node->ltag && node->left) // 如果有前驱并且还没到中序第一个节点
        {
            node = node->left;
        }
        if (!node->ltag) // 说明有左孩子，说明是因为不满足第一个条件退出循环
        {
            return node->left->val;
        }
        else // 是因为第二个条件不满足退出循环
        {
            return -1;
        }
    }
}

// 1 2 4 -1 -1 5 -1 -1 3 6 8 -1 -1 -1 7 9 11 -1 -1 -1 10 -1 -1
int main()
{
    cout << "Please input the values of per node: " << endl;
    ThreadTreeNode *root = create_thread_tree_main();

    int k;
    cout << "Please input the value of k: ";
    cin >> k;
    int result = find_post_in_middle_tread_tree(root, k);
    string str = result != -1 ? "The pre node in post sequence is: " + to_string(result) : "No pre in the post sequence.";
    cout << str;
    return 0;
}