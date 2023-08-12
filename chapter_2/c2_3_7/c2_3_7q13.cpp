//
// Created by Hleonor on 2023-08-12.
//
#include "chapter_2_header.h"

// 思路：先合并，再反转
ListNode* inverted_in_place(ListNode* current_node, ListNode* pre)
{
    ListNode* p = current_node->next;
    if (p == nullptr)
    {
        current_node->next = pre;
        return current_node;
    }
    current_node->next = pre;
    pre = current_node;
    return inverted_in_place(p, pre);
}

ListNode* merge(ListNode* head_1, ListNode* head_2)
{
    ListNode* head = new ListNode;
    head->next = nullptr;

    ListNode* current_node = head;
    ListNode* current_node_1 = head_1->next;
    ListNode* current_node_2 = head_2->next;

    while (current_node_1 && current_node_2)
    {
        if (current_node_2->value <= current_node_1->value)
        {
            // 先记住较大value的节点的后继
            ListNode* rear = current_node_2->next;
            // 然后再进行连接
            current_node->next = current_node_2;
            current_node_2->next = nullptr;
            current_node_2 = rear;
        }
        else
        {
            ListNode* rear = current_node_1->next;
            current_node->next = current_node_1;
            current_node_1->next = nullptr;
            current_node_1 = rear;
        }
        current_node = current_node->next;
    }
    if (current_node_1)
    {
        current_node->next = current_node_1;
    }
    if (current_node_2)
    {
        current_node->next = current_node_2;
    }
    return head;
}

ListNode* build_1()
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
    node1->value = 3;
    node1->number = 2;
    node1->next = nullptr;
    node0->next = node1;

    ListNode *node2 = new ListNode;
    node2->value = 5;
    node2->number = 3;
    node2->next = nullptr;
    node1->next = node2;

    ListNode *node3 = new ListNode;
    node3->value = 7;
    node3->number = 4;
    node3->next = nullptr;
    node2->next = node3;

    ListNode *node4 = new ListNode;
    node4->value = 9;
    node4->number = 5;
    node4->next = nullptr;
    node3->next = node4;

    ListNode *node5 = new ListNode;
    node5->value = 11;
    node5->number = 6;
    node5->next = nullptr;
    node4->next = node5;

    return head;
}
ListNode* build_2()
{
    ListNode *head = new ListNode;
    head->value = INT_MIN;
    head->number = 0;
    head->next = nullptr;

    ListNode *node0 = new ListNode;
    node0->value = 2;
    node0->number = 1;
    node0->next = nullptr;
    head->next = node0;

    ListNode *node1 = new ListNode;
    node1->value = 4;
    node1->number = 2;
    node1->next = nullptr;
    node0->next = node1;

    ListNode *node2 = new ListNode;
    node2->value = 6;
    node2->number = 3;
    node2->next = nullptr;
    node1->next = node2;

    ListNode *node3 = new ListNode;
    node3->value = 8;
    node3->number = 4;
    node3->next = nullptr;
    node2->next = node3;

    ListNode *node4 = new ListNode;
    node4->value = 10;
    node4->number = 5;
    node4->next = nullptr;
    node3->next = node4;

    ListNode *node5 = new ListNode;
    node5->value = 12;
    node5->number = 6;
    node5->next = nullptr;
    node4->next = node5;

    return head;
}

int main()
{
    // 构建一个链表，内容是1 3 5 7 9
    ListNode* head_1 = build_1();
    ListNode* head_2 = build_2();
    ListNode* head = merge(head_1, head_2);
    head = inverted_in_place(head, nullptr);
    output_list(head->next);
    return 0;
}