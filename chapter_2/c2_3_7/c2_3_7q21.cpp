//
// Created by Hleonor on 2023-08-15.
//
#include <iostream>
using namespace std;

struct ListNode
{
    int value;
    bool visited;
    ListNode* next;
};

bool hasCircle(ListNode* head)
{
    ListNode* cur = head;
    while (cur)
    {
        if (cur->visited)
        {
            return true;
        }
        cur->visited = true;
        cur = cur->next;
    }
    return false;
}

int main()
{
    // 构建一个存在环的链表，即最后一个节点的指针指向了环中的某一个节点
    ListNode* head = new ListNode;
    head->value = INT_MIN;
    head->visited = false;
    head->next = nullptr;
    ListNode* cur = head;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        ListNode* node = new ListNode;
        node->value = tmp;
        node->visited = false;
        node->next = nullptr;
        cur->next = node;
        cur = node;
    }
    // 最后一个节点指向第一个节点
    cur->next = head->next;
    string hasCircleStr = hasCircle(head) ? "true" : "false";
    cout << hasCircleStr << endl;
    return 0;
}
