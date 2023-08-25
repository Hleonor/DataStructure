//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

// 要想得到祖先，就需要通过栈来保存路径
// 采用使用栈来模拟递归后续遍历的方式，当某一时刻找到值为x的节点的时候，此时栈中保存的就是所有的祖先节点，逐个弹栈即可
// 1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 10 -1 -1 11 -1 -1 7 -1 -1
void find_x_ancestor(TreeNode* root, int x)
{
    stack<TreeNode*> myStack;
    TreeNode* cur = root;
    TreeNode* tmp_right = nullptr;
    while (true)
    {
        if (cur == nullptr && myStack.empty())
        {
            break;
        }

        while (cur)
        {
            // 假设某一次压栈遇到的节点为值为x的节点，则直接将栈中的所有节点弹栈，
            if (cur->val == x)
            {
                cout << "Ancestors are: ";
                while (!myStack.empty())
                {
                    cout << myStack.top()->val << " ";
                    myStack.pop();
                }
                return;
            }
            myStack.push(cur);
            cur = cur->left;
        }

        // 一直压栈到没有左孩子的节点
        if (myStack.top()->right && myStack.top()->right != tmp_right)
        {
            cur = myStack.top()->right;
        }
        else // 没有右孩子了或者右子树已经访问过，此时访问当前节点
        {
            /*cout << myStack.top()->val << " ";*/
            tmp_right = myStack.top(); // 记录刚刚弹栈的节点
            myStack.pop();
        }

    }
    cout << "Can't find node with value x." << endl;
}

int main()
{
    cout << "Please input the values of per node: " << endl;
    TreeNode* root = build_tree();
    int x = -1;
    cout << "Please input value x: ";
    cin >> x;
    cout << endl;
    find_x_ancestor(root, x);
    return 0;
}