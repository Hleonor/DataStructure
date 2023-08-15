//
// Created by Hleonor on 2023-08-15.
//
#include "chapter_2_header.h"

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

void cross_merge(ListNode* head_1, ListNode* head_2)
{
    ListNode* cur_1 = head_1;
    ListNode* cur_2 = head_2;
    while (cur_1 && cur_2)
    {
        // 先记住后继
        ListNode* behind_1 = cur_1->next;
        ListNode* behind_2 = cur_2->next;

        // 进行交叉连接
        cur_1->next = cur_2;
        cur_2->next = behind_1;

        // 进行下一轮操作
        cur_1 = behind_1;
        cur_2 = behind_2;
    }
}

void resort_link(ListNode* head)
{
    int length = 0;
    ListNode* cur_1 = head->next;
    while (cur_1)
    {
        length++;
        cur_1 = cur_1->next;
    }
    cur_1 = head->next;
    for (int i = 1; i < length / 2; i++) // 走到前半段的最后一个节点
    {
        cur_1 = cur_1->next;
    }
    // 将后半部分的链表进行逆置，并得到逆置以后的子链表头节点
    ListNode* cur_2 = inverted_in_place(cur_1->next, nullptr);
    cur_1->next = nullptr; // 将前半部分的链表尾节点的next置为nullptr
    // 将两个链表进行合并
    cross_merge(head->next, cur_2);
}


int main()
{
    ListNode* head = build_list();
    resort_link(head);
    output_list(head);
    return 0;
}