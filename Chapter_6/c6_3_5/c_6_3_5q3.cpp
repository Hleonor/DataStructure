//
// Created by Mocshere on 2023-09-07.
//
#include <algorithm>
#include "chapter6_header.h"
int visit[999] = {0};

void dfs(int n) // 找到一条路径即可；该函数必然能够遍历一个连通分量内的所有节点
{
    if (n == 0)
    {
        cout << "The graph is empty." << endl;
    }
    stack<int> myStack;
    // 每当走到一个空指针的时候，说明找到了一条路径，此时把栈中的所有节点输出就可以得到一条深度优先的路径
    myStack.push(head[1].VerName);
    visit[myStack.top()] = true;
    /*int father = -1;*/
    while (myStack.size() != n) // 还存在节点没有访问的时候，继续循环
    {
        int number = myStack.top();
        // 现在头节点中找到该链表
        HeadNode headNode;
        for (int i = 1; i <= n; i++)
        {
            if (head[i].VerName == number)
            {
                headNode = head[i];
                break;
            }
        }
        EdgeNode* node = headNode.adjacent;
        while (node)
        {
            if (visit[node->VerAdj] == false)
            {
                myStack.push(node->VerAdj);
                /*father = node->VerAdj;*/
                visit[node->VerAdj] = true;
                break;
            }
            node = node->link;
        }
        if (node == nullptr) // 如果在遍历某个链表的时候，走到了尾节点，说明所有的顶点也都已经被访问过了
        {
            break;
        }
    }
    string path;
    while (!myStack.empty())
    {
        path += to_string(myStack.top()) + " ";
        myStack.pop();
    }
    reverse(path.begin(), path.end());
    cout << path << endl;
}

/*
 *  1 2 0
    1 3 0
    1 4 0
    2 1 0
    2 3 0
    3 1 0
    3 2 0
    3 4 0
    3 5 0
    4 1 0
    4 3 0
    4 5 0
    5 3 0
    5 4 0
 */
int main()
{
    int n;
    int e;
    cout << "please input node number:";
    cin >> n;
    cout << "please input edge number:";
    cin >> e;
    getMap(n, e);
    dfs(n);
    return 0;
}
