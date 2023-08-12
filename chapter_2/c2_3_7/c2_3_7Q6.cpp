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

void sort_list(ListNode* head)
{
    ListNode* current_node = head->next; // current_node从第二个节点开始
    head->next = nullptr; // 构造一个新的链表

    while (current_node)
    {
        ListNode* p = head;
        ListNode* pre = head;
        ListNode* rear_cur = current_node->next;
        while (p && p->value < current_node->value)
        {
            pre = p;
            p = p->next;
        }
        pre->next = current_node;
        current_node->next = p;

        // 退出循环的时候，如果p == current_node，说明此时current_node不用动，就在最尾的位置，往下继续看一个就行了
        current_node = rear_cur;
    }
}

int main()
{
    ListNode *head = new ListNode;
    head->value = INT_MIN;
    head->number = 0;
    head->next = nullptr;

    ListNode *node0 = new ListNode;
    node0->value = 1;
    node0->number = 1;
    node0->next = nullptr;
    head->next = node0;

    ListNode *node1 = new ListNode;
    node1->value = 1;
    node1->number = 2;
    node1->next = nullptr;
    node0->next = node1;

    ListNode *node2 = new ListNode;
    node2->value = 1;
    node2->number = 3;
    node2->next = nullptr;
    node1->next = node2;

    ListNode *node3 = new ListNode;
    node3->value = 1;
    node3->number = 4;
    node3->next = nullptr;
    node2->next = node3;

    ListNode *node4 = new ListNode;
    node4->value = 9;
    node4->number = 5;
    node4->next = nullptr;
    node3->next = node4;

    ListNode *node5 = new ListNode;
    node5->value = 1;
    node5->number = 6;
    node5->next = nullptr;
    node4->next = node5;
    sort_list(head);
    ListNode* p = head->next;
    while (p)
    {
        cout << p->value << " ";
        p = p->next;
    }
    return 0;
}