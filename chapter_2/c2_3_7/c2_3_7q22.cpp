//
// Created by Hleonor on 2023-08-15.
//
#include "chapter_2_header.h"

bool find_k_node(ListNode *head, int k)
{
    // 首先遍历一遍链表，得到表长
    int length = 0;
    ListNode* cur = head->next;
    while (cur) // 哨兵节点不作为
    {
        length++;
        cur = cur->next;
    }
    if (k > length)
    {
        return false;
    }
    // 输出倒数第k个位置上的节点，就是输出正数第length - k个节点
    int cnt = length - k;
    cur = head->next;
    while (cnt)
    {
        cur = cur->next;
        cnt--;
    }
    cout << cur->value << endl;
    return true;
}

int main()
{
    ListNode* head = new ListNode;
    head->value = INT_MIN;
    head->next = nullptr;
    ListNode* cur = head;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        ListNode* node = new ListNode;
        node->value = tmp;
        node->next = nullptr;
        cur->next = node;
        cur = node;
    }
    int k;
    cin >> k;
    bool find = find_k_node(head, k);
    string findStr = find ? "true" : "false";
    cout << findStr << endl;
    return 0;
}