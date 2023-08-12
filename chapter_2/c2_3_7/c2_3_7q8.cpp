//
// Created by Hleonor on 2023-08-12.
//
#include <iostream>
#include "chapter_2_header.h"
using namespace std;

ListNode* find_public_node(ListNode* head_1, ListNode* head_2)
{
    int length_1 = 0;
    ListNode* current_node = head_1->next;
    while (current_node)
    {
        length_1++;
        current_node = current_node->next;
    }

    int length_2 = 0;
    current_node = head_2->next;
    while (current_node)
    {
        length_2++;
        current_node = current_node->next;
    }

    int difference = length_1 - length_2;
    bool flag = false;
    if (difference > 0)
    {
        flag = true;
        current_node = head_1->next;
        while (current_node && difference > 0)
        {
            current_node = current_node->next;
            difference--;
        }
    }
    else
    {
        current_node = head_2->next;
        while (current_node && difference < 0)
        {
            current_node = current_node->next;
            difference++;
        }
    }
    // 同步遍历
    ListNode* p1;
    ListNode* p2;
    if (flag) // 表一比较长
    {
        p1 = current_node;
        p2 = head_2->next;
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    else
    {
        p1 = head_2->next;
        p2 = current_node;
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return p1;
}

int main()
{
    return 0;
}