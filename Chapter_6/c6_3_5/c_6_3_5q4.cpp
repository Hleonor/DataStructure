//
// Created by Mocshere on 2023-09-07.
//
#include <algorithm>
#include "chapter6_header.h"
int visit[999] = {0};

int pre_node[999] = {0}; // 默认0表示没有前驱，当存在多个前驱的时候，这个办法就不生效了

bool hasPathBfs(int n, int start, int end)
{
    bool book = false;
    queue<int> myQueue;
    myQueue.push(head[1].VerName);
    visit[head[1].VerName] = true;
    while (!myQueue.empty())
    {
        int number = myQueue.front();
        myQueue.pop();
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
                pre_node[node->VerAdj] = number;
                visit[node->VerAdj] = true;
                myQueue.push(node->VerAdj);
                break;
            }
            node = node->link;
        }
    }
    while (pre_node[end] != 0)
    {
        if (pre_node[end] == start)
        {
            book = true;
        }
        end = pre_node[end];
    }
    return book;
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
