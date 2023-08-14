//
// Created by Hleonor on 2023-08-14.
//
#include <iostream>
using namespace std;

struct ListNode
{
    int value;
    ListNode* next;
    ListNode* pre;
};

bool isCircle(ListNode* head)
{
    // 先走一遍得到表长，然后再从两头走
    ListNode* rear = nullptr;
    ListNode* cur = head->next; // 循环双链表不带哨兵节点
    int length = 0;
    if (cur)
    {
        length++;
    }
    else
    {
        return false;
    }

    while (cur->next)
    {
        length++;
        cur = cur->next;
    }
    rear = cur;
    ListNode* front = head->next;
    for (int i = 1; i <= length / 2; i++)
    {
        if (front->value != rear->value)
        {
            return false;
        }
        front = front->next;
        rear = rear->pre;
    }
    return true;
}
int main()
{
    // 构建一个双循环链表，允许用户手动输入数值
    ListNode* head = new ListNode;
    head->value = INT_MIN;
    head->next = nullptr;
    head->pre = nullptr;
    ListNode* cur = head;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        ListNode* next = new ListNode;
        next->value = tmp;
        next->next = nullptr;
        next->pre = cur;
        cur->next = next;
        cur = next;
    }

    cout << isCircle(head) << endl;
    return 0;
}