//
// Created by Mocshere on 2023-09-07.
//
#include "chapter6_header.h"
int visit[999] = {0};

// 每次难以处理的都是循环的入口
void dfs(int n)
{
    if (head == nullptr)
    {
        cout << "The graph is empty." << endl;
    }
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur = i;
        visit[i] = true;
        EdgeNode* node = head[i].adjacent;
        while (node)
        {

            node = node->link;
        }
    }
}

int main()
{
    int n;
    int e;
    cout << "please input node number:";
    cin >> n;
    cout << "please input edge number:";
    cin >> e;
    getMap(n, e);

    return 0;
}
