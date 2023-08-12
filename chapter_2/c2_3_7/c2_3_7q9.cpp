//
// Created by Hleonor on 2023-08-12.
//
#include <iostream>
#include "chapter_2_header.h"
using namespace std;

// 最开始的想法是不允许使用数组作为辅助空间，那就用一个新的链表作为辅助空间，但是这样不仅时间复杂度是n²，而且空间复杂度也是n
// 效果不好，所以采用时间复杂度n²，空间复杂度1的做法，也就是答案的做法
void output_list_in_sort(ListNode* head)
{
    while (head->next) // 如果还有有效节点的话就仍然需要判断
    {
        ListNode* pre = head;
        ListNode* current_node = head->next;
        ListNode* min_pre = head;
        ListNode* min_node = head->next;
        int min = INT_MAX;
        while (current_node)
        {
            if (current_node->value <= min)
            {
                min = current_node->value;
                min_pre = pre;
                min_node = current_node;
            }
            pre = current_node;
            current_node = current_node->next;
        }
        cout << min_node->value << " ";
        min_pre->next = min_node->next;
        free(min_node);
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
        next->value = i;
        next->number = i;
        next->next = nullptr;
        currentNode->next = next;
        currentNode = next;
    }
    output_list_in_sort(head);
    return 0;
}
