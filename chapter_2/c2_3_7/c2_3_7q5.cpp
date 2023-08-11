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
        next->value = i;
        next->number = i;
        next->next = nullptr;
        currentNode->next = next;
        currentNode = next;
    }
    ListNode* p = inverted_in_place(head, nullptr);
    while (p)
    {
        cout << p->value << " ";
        p = p->next;
    }
    return 0;
}