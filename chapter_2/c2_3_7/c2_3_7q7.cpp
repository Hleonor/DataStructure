//
// Created by Hleonor on 2023-08-12.
//
#include <iostream>

using namespace std;
struct ListNode
{
    int number;
    int value;
    ListNode *next;
};

void delete_between_s_t(ListNode *head, int s, int t)
{
    ListNode *pre = head;
    ListNode *current_node = head->next;
    while (current_node)
    {
        if (current_node->value <= t && current_node->value >= s)
        {
            pre->next = current_node->next;
            current_node = current_node->next;
            continue;
        }
        pre = current_node;
        current_node = current_node->next;
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
    node5->value = 5;
    node5->number = 6;
    node5->next = nullptr;
    node4->next = node5;
    delete_between_s_t(head, 1, 3);
    ListNode *p = head->next;
    while (p)
    {
        cout << p->value << " ";
        p = p->next;
    }
    return 0;
}
