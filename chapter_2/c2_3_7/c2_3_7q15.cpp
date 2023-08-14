//
// Created by Hleonor on 2023-08-13.
//
#include "chapter_2_header.h"

// 与第十四题不同，这题要求在原来的链表上进行操作而不是通过创建新的节点来构造公共元素链表
ListNode* find_public(ListNode* head_1, ListNode* head_2)
{
    ListNode* head = new ListNode;
    head->next = nullptr;
    head->value = INT_MIN;
    ListNode* cur = head;
    ListNode* cur_1 = head_1->next;
    ListNode* cur_2 = head_2->next;
    while (cur_1 && cur_2)
    {
        if (cur_1->value < cur_2->value) // 如果cur_2的value值大于cur_1的value值，那么第二个链表往后的值只会更大，所以移动小的
        {
            ListNode* tmp = cur_1;
            cur_1 = cur_1->next;
            ::free(tmp);
        }
        else if (cur_1->value > cur_2->value)
        {
            ListNode* tmp = cur_2;
            cur_2 = cur_2->next;
            ::free(tmp);
        }
        else
        {
            // 先分别记住当前两个cur节点的后继节点
            ListNode* rear_1 = cur_1->next;
            ListNode* rear_2 = cur_2->next;

            // 连接
            cur->next = cur_1;
            cur = cur->next;

            ListNode* tmp  = cur_2;
            // 释放并往后走
            ::free(tmp);

            cur_1 = rear_1;
            cur_2 = rear_2;
        }
    }
    while (cur_1)
    {
        ListNode* tmp = cur_1;
        cur_1 = cur_1->next;
        ::free(tmp);
    }
    while (cur_2)
    {
        ListNode* tmp = cur_2;
        cur_2 = cur_2->next; // 检查了半天，发现原来是这里写成了cur_1，而cur_1的指针早就空了，所以内存访问错误了
        ::free(tmp);
    }
    return head;
}

int main()
{
    // 分别构造两个有公共元素的链表
    ListNode* head_1 = new ListNode;
    ListNode* head_2 = new ListNode;
    head_1->next = nullptr;
    head_2->next = nullptr;
    head_1->value = INT_MIN;
    head_1->number = 0;
    head_2->number = 0;
    head_2->value = INT_MIN;
    ListNode* cur_1 = head_1;
    ListNode* cur_2 = head_2;
    for (int i = 0; i < 10; ++i)
    {
        ListNode* node = new ListNode;
        node->value = i;
        node->number = i + 1;
        node->next = nullptr;
        cur_1->next = node;
        cur_1 = cur_1->next;
    }
    for (int i = 5; i < 15; ++i)
    {
        ListNode* node = new ListNode;
        node->value = i;
        node->number = i - 4;
        node->next = nullptr;
        cur_2->next = node;
        cur_2 = cur_2->next;
    }
    cur_1->next = nullptr;
    cur_2->next = nullptr;

    // 找到公共元素
    ListNode* head = find_public(head_1, head_2);
    output_list(head);
    return 0;
}