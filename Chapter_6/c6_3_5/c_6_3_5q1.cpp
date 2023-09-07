//
// Created by Mocshere on 2023-09-07.
//
#include "chapter6_header.h"

// 只要没有回路的图就是树
// 不能单纯使用n - 1条边来判断是不是树，因为可能会出现孤立的点
// 使用邻接表可以判断一个图是不是存在回路，即只需要保存当前节点的父节点即可
// 父节点的意思是指，假如刚刚访问了边<i, j>，先访问边表节点i的条目
// 那么访问节点j的时候，父节点就是i，如果访问到某个节点之前被访问过，但是不是父节点i
// 则说明出现了回路
int visit[999] = {0};

bool dfs(int cur, int father)
{
    visit[cur] = true;
    EdgeNode* node = head[cur].adjacent;
    while (node)
    {
        if (visit[node->VerAdj] == 0)
        {
            if (dfs(node->VerAdj, cur))
            {
                return false;
            }
        }
        else if (node->VerAdj != father) // 如果当前节点被访问过，但是不是父节点，说明存在回路，即不是树
        {
            return false;
        }
        node = node->link;
    }
    return true;
}

bool hasCircle(int n)
{
    int cnt = 0; // 连通分量个数
    for (int i = 0; i < n; i++)
    {
        if (visit[n] == false)
        {
            if (dfs(0, -1) == false)
            {
                return false;
            }
            cnt++;
        }
    }
    if (cnt > 1)
    {
        return false;
    }
    return true;
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

    cout << hasCircle(n);

    return 0;
}
