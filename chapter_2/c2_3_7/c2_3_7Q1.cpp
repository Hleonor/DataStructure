//
// Created by Hleonor on 2023-08-11.
//
#include <iostream>

using namespace std;

struct ListNode
{
    int number;
    int value;
    ListNode *next;
};

ListNode* delete_x(ListNode *head, int x)
{
    ListNode *currentNode = head;
    // 先不管头节点的value是不是x，退出循环的时候再特判
    while (currentNode->next)
    {
        if (currentNode->next->value == x)
        {
            ListNode* p = currentNode->next;
            currentNode->next = currentNode->next->next;
            ::free(p);
            continue;
        }
        currentNode = currentNode->next;
    }
    // 最后退出循环的时候，除了头节点都已经检查完了，此时检查头节点的value是不是x
    if (head->value == x)
    {
        ListNode* p = head;
        head = head->next;
        ::free(p);
    }
    return head;
}

int main()
{
    ListNode *head = new ListNode;
    head->value = 0;
    head->next = nullptr;
    ListNode *currentNode = head;
    // 手动构造链表，内容为1 2 3 4 4 5 6 6 6 7 8 9
    for (int i = 1; i < 10; i++)
    {
        ListNode *next = new ListNode;
        next->value = 1;
        next->number = i;
        next->next = nullptr;
        currentNode->next = next;
        currentNode = next;
    }
    head = delete_x(head, 1);
    ListNode *next = head->next;
    while (next)
    {
        cout << next->value << " ";
        next = next->next;
    }
    return 0;
}
