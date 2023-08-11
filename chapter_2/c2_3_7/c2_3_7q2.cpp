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

void delete_x(ListNode *currentNode, ListNode *next, int x)
{
    if (next == nullptr)
    {
        return;
    }
    else
    {
        if (next->value == x)
        {
            currentNode->next = next->next;
            free(next);
            delete_x(currentNode, currentNode->next, x);
        }
        else
        {
            delete_x(currentNode->next, currentNode->next->next, x);
        }
    }
}

int main()
{
    ListNode *head = new ListNode;
    head->value = 0;
    head->next = nullptr;
    ListNode *currentNode = head;
    // 手动构造链表，内容为1 2 3 4 4 5 6 6 6 7 8 9
    for (int i = 1; i < 2; i++)
    {
        ListNode *next = new ListNode;
        next->value = 1;
        next->number = i;
        next->next = nullptr;
        currentNode->next = next;
        currentNode = next;
    }
    delete_x(head, head->next, 1);
    ListNode *next = head->next;
    while (next)
    {
        cout << next->value << " ";
        next = next->next;
    }
    return 0;
}