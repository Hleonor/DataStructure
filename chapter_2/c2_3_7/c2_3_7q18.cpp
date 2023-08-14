//
// Created by Hleonor on 2023-08-14.
//
#include "chapter_2_header.h"

// 连接两个循环单链表
void link2Lists(ListNode* head_1, ListNode* head_2)
{
    ListNode* rear_1 = head_1;
    while (rear_1->next)
    {
        rear_1 = rear_1->next;
    }

    ListNode* rear_2 = head_2;
    while (rear_2->next)
    {
        rear_2 = rear_2->next;
    }

    rear_1->next = head_2->next;
    rear_2->next = head_1;

}
int main()
{
    ListNode* head_1 = new ListNode;
    head_1->value = INT_MIN;
    head_1->next = nullptr;
    ListNode* cur_1 = head_1;
    int n_1;
    cin >> n_1;
    for (int i = 0; i < n_1; i++)
    {
        int tmp;
        cin >> tmp;
        ListNode* node = new ListNode;
        node->value = tmp;
        node->next = nullptr;
        cur_1->next = node;
        cur_1 = cur_1->next;
    }
    int n_2;
    cin >> n_2;
    ListNode* head_2 = new ListNode;
    head_2->value = INT_MIN;
    head_2->next = nullptr;
    ListNode* cur_2 = head_2;
    for (int i = 0; i < n_2; i++)
    {
        int tmp;
        cin >> tmp;
        ListNode* node = new ListNode;
        node->value = tmp;
        node->next = nullptr;
        cur_2->next = node;
        cur_2 = cur_2->next;
    }
    link2Lists(head_1, head_2);
    head_1 = head_1->next;
    return 0;
}