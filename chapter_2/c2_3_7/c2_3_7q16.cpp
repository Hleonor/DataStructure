//
// Created by Hleonor on 2023-08-14.
//
#include "chapter_2_header.h"
using namespace std;

bool find_public_node(ListNode* short_list, ListNode* long_list) // 首先找到第一个相同元素的节点
{
    ListNode* short_one = short_list;
    ListNode* long_one = long_list;
    while (long_one && long_one->value < short_one->value) // 固定短的，找长的
    {
        long_one = long_one->next;
    }
    if (long_one && long_one->value == short_one->value)
    {
        ListNode* cur_1 = short_one;
        ListNode* cur_2 = long_one;
        while (cur_1 && cur_2)
        {
            if (cur_1->value != cur_2->value)
            {
                return false;
            }
            cur_1 = cur_1->next;
            cur_2 = cur_2->next;
        }
    }
    else
    {
        return false;
    }
    return true;
}

bool isSubsequence(ListNode* head_1, ListNode* head_2)
{
    ListNode* cur_1 = head_1->next;
    ListNode* cur_2 = head_2->next;
    // 检查谁应该是子序列，即比较两个链表第一个元素的大小
    // 表中第一个元素较大者为可能的子序列
    return cur_1->value <= cur_2->value ? find_public_node(cur_2, cur_1) : find_public_node(cur_1, cur_2);
}

int main()
{
    ListNode* head_1 = new ListNode;
    ListNode* head_2 = new ListNode;
    head_1->next = nullptr;
    head_2->next = nullptr;
    head_1->value = INT_MIN;
    head_2->value = INT_MIN;
    int n, m;
    cin >> n >> m;
    ListNode* cur_1 = head_1;
    ListNode* cur_2 = head_2;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        ListNode* node = new ListNode;
        node->value = tmp;
        node->next = nullptr;
        cur_1->next = node;
        cur_1 = cur_1->next;
    }
    for (int i = 0; i < m; ++i)
    {
        int tmp;
        cin >> tmp;
        ListNode* node = new ListNode;
        node->value = tmp;
        node->next = nullptr;
        cur_2->next = node;
        cur_2 = cur_2->next;
    }
    cur_1->next = nullptr;
    cur_2->next = nullptr;
    cout << isSubsequence(head_1, head_2) << endl;
    return 0;
}