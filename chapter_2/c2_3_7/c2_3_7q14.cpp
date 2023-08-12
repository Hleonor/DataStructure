//
// Created by Hleonor on 2023-08-12.
//
#include "chapter_2_header.h"

ListNode* build_by_public(ListNode* head_1, ListNode* head_2)
{
    ListNode* head = new ListNode;
    head->next = nullptr;
    ListNode* cur = head;
    ListNode* cur_1 = head_1->next;
    ListNode* cur_2 = head_2->next;
    while (cur_1 && cur_2)
    {
        if (cur_1->value > cur_2->value)
        {
            cur_2 = cur_2->next;
        }
        else if (cur_1->value < cur_2->value)
        {
            cur_1 = cur_1->next;
        }
        else
        {
            ListNode* node = new ListNode;
            node->value = cur_1->value;
            node->next = nullptr;

            cur->next = node;

            cur = cur->next;
            cur_1 = cur_1->next;
            cur_2 = cur_2->next;
        }
    }
    return head;
}

int main()
{
    ListNode* head_1 = build_list();
    ListNode* head_2 = build_list();
    ListNode* head = build_by_public(head_1, head_2);
    output_list(head);
    return 0;
}