//
// Created by Hleonor on 2023-08-12.
//
#include <iostream>
#include "chapter_2_header.h"
using namespace std;

ListNode** seperate2List(ListNode* head)
{
    ListNode** listHead = new ListNode*[2];
    listHead[0] = new ListNode;
    listHead[1] = new ListNode;

    ListNode* currentNode = head->next;
    ListNode* c1 = listHead[0];
    ListNode* c2 = listHead[1];

    int cnt = 1;
    while (currentNode)
    {
        if (cnt % 2) // 奇数
        {
            ListNode* node = new ListNode;
            node->value = currentNode->value;
            c1->next = node;
            c1 = node;
        }
        else
        {
            ListNode* node = new ListNode;
            node->value = currentNode->value;
            c2->next = node;
            c2 = node;
        }
        ListNode* p = currentNode;
        head->next = currentNode->next;
        currentNode = currentNode->next;
        free(p);
        cnt++;
    }
    return listHead;
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
    ListNode** listHead = seperate2List(head);
    ListNode* c1 = listHead[0]->next;
    ListNode* c2 = listHead[1]->next;
    while (c1)
    {
        cout << c1->value << " ";
        c1 = c1->next;
    }
    cout << endl;
    while (c2)
    {
        cout << c2->value << " ";
        c2 = c2->next;
    }

    return 0;
}