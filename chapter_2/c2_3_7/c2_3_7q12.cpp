//
// Created by Hleonor on 2023-08-12.
//
#include <iostream>
#include "chapter_2_header.h"
using namespace std;

void delete_duplicated(ListNode *head)
{
    ListNode* current_node = head;
    while (current_node)
    {
        if (current_node->next && current_node->next->value == current_node->value)
        {
            ListNode* tmp = current_node->next;
            current_node->next = current_node->next->next;
            free(tmp);
            continue;
        }
        current_node = current_node->next;
    }
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
    delete_duplicated(head);
    output_list(head);
    return 0;
}
