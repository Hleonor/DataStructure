//
// Created by Mocshere on 2023-09-07.
//
#include <algorithm>
#include "chapter6_header.h"
int visit[999] = {0};

int pre_node[999] = {0}; // 默认0表示没有前驱，当存在多个前驱的时候，这个办法就不生效了

bool hasPathBfs(int n, int start, int end)
{
    queue<int> myQueue;
    myQueue.push(head[1].VerName);
    visit[head[1].VerName] = true;
    if (head[1].VerName == end)
    {
        return true;
    }
    while (!myQueue.empty())
    {
        int number = myQueue.front();
        myQueue.pop();
        HeadNode cur_head = head[number];
        for (EdgeNode* node = cur_head.adjacent; node != nullptr; node = node->link)
        {
            if (node->VerAdj == end)
            {
                return true;
            }
            if (visit[node->VerAdj] == false)
            {
                visit[node->VerAdj] = true;
                myQueue.push(node->VerAdj);
            }
        }
    }
    return false;
}

void dfs(int cur, int end)
{
    EdgeNode* node = head[cur].adjacent;
    while (node)
    {
        if (node->VerAdj == end)
        {
            visit[end] = true;
            return;
        }
        if (visit[node->VerAdj] == false)
        {
            visit[node->VerAdj] = true;
            dfs(node->VerAdj, end);
        }
        node = node->link;
    }
}

bool hasPathDfs(int n, int start, int end)
{
    bool book = false;
    dfs(start, end);
    if (visit[end])
    {
        book = true;
    }
    return book;
}

/*
 *  1 3 0
    3 4 0
    4 2 0
    2 5 0
 */

/*
 *  1 3 0
    3 4 0
    4 2 0
    2 5 0
    1 5 0
    5 4 0
    4 1 0
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

    /*cout << hasPathDfs(n, 1, 1);*/
    cout << hasPathBfs(n, 5, 1);

    return 0;
}
