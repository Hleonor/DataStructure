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

int find_min(ListNode* head)
{
    ListNode* current_node = head;
    int result = INT_MAX;
    while (current_node)
    {
        if (current_node->value <= result)
        {
            result = current_node->value;
        }
        current_node = current_node->next;
    }
    return result;
}

int main()
{
    ListNode *head = new ListNode;
    head->value = 0;
    head->next = nullptr;
    ListNode *node1 = new ListNode;
    node1->value = 4;
    node1->next = nullptr;
    head->next = node1;
    ListNode *node2 = new ListNode;
    node2->value = 1900;
    node2->next = nullptr;
    node1->next = node2;
    ListNode *node3 = new ListNode;
    node3->value = -1;
    node3->next = nullptr;
    node2->next = node3;
    ListNode *node4 = new ListNode;
    node4->value = 90;
    node4->next = nullptr;
    node3->next = node4;
    ListNode *node5 = new ListNode;
    node5->value = 3;
    node5->next = nullptr;
    node4->next = node5;
    int result = find_min(head);
    cout << result << endl;
    return 0;
}