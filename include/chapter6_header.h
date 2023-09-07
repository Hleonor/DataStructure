//
// Created by Hleonor on 2023-08-20.
//

#ifndef DATASTRUCTURE_CHAPTER5_HEADER_H
#define DATASTRUCTURE_CHAPTER5_HEADER_H
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define MAX_LENGTH 999999
struct EdgeNode // 边表节点
{
    int VerAdj; // 邻接点的下标
    int cost; // 与表头相连边的权值
    struct EdgeNode* link; // 指向下一个边链表节点的指针
    EdgeNode() {};
    EdgeNode(int VerAdj, int cost) : cost(cost), VerAdj(VerAdj), link(NULL) {};
};

struct HeadNode
{
    int VerName; // 表头节点
    EdgeNode* adjacent; // 存放边链表的头指针
    HeadNode() {};
    HeadNode(int VerName) : VerName(VerName), adjacent(NULL) {};
};

HeadNode* head = new HeadNode[1000];

void getMap(int n, int e)
{
    for (int i = 0; i < n; i++)
    {
        head[i].VerName = i;
        head[i].adjacent = nullptr;
    }

    int edgeHead, edgeTail, cost;
    for (int i = 0; i < e; i++)
    {
        // 有向图，只进行正向连接操作
        // 不断来节点，然后不断地连到表头之后，类似于队列的操作
        /*cout << "start end cost:";*/
        cin >> edgeHead >> edgeTail >> cost;

        EdgeNode* node = new EdgeNode;
        node->cost = cost;
        node->VerAdj = edgeTail;
        node->link = head[edgeHead].adjacent;
        head[edgeHead].adjacent = node;
    }
}

void show_graph(int n)
{
    for (int i = 0; i < n; i++)
    {
        EdgeNode* node = head[i].adjacent;
        while (node)
        {
            cout << head[i].VerName << " ---> " << node->VerAdj << " cost: " << node->cost;
            cout << endl;
            node = node->link;
        }
    }
}

#endif //DATASTRUCTURE_CHAPTER5_HEADER_H
