//
// Created by Hleonor on 2023-08-15.
//
#include <iostream>

using namespace std;

struct ListNode
{
    int value;
    int freq;
    ListNode *next;
    ListNode *pre;
};

ListNode *Locate(ListNode *head, int x)
{
    // 先找到该节点
    ListNode *cur = head->next;
    while (cur)
    {
        if (cur->value == x)
        {
            cur->freq++;
            break;
        }
        cur = cur->next;
    }
    if (!cur) // 没找到
    {
        return nullptr;
    }
    // 如果找到的是第一个节点，那么它原来的频度就是最高的，不需要调整
    while (cur->pre != head && cur->freq >= cur->pre->freq)
    {
        // 和前面的节点进行交换
        ListNode *front = cur->pre;
        ListNode *behind = cur->next;
        // 后继指针有可能是空指针，所以需要特殊判断
        front->next = behind;
        if (behind)
        {
            behind->pre = front;
        }
        cur->next = front;
        cur->pre = front->pre;
        front->pre->next = cur;
        front->pre = cur;
    }
    return cur;

}

int main()
{
    // 构建一个非循环双向链表，允许用户自己输入数值
    ListNode *head = new ListNode;
    head->value = INT_MIN;
    head->freq = 0;
    head->next = nullptr;
    head->pre = nullptr;
    ListNode *cur = head;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        ListNode *node = new ListNode;
        node->value = tmp;
        node->freq = 0;
        node->next = nullptr;
        node->pre = cur;
        cur->next = node;
        cur = node;
    }
    int x;
    ListNode *res = nullptr;
    // 多次定位x，每次定位后输出链表中的所有元素
    while (cin >> x)
    {
        res = Locate(head, x);
        if (res)
        {
            cout << res->value << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
        // 输出链表中的所有元素
        cur = head->next;
        while (cur)
        {
            // 输出元素以及对应的频度
            cout << "( " << cur->value << " " << cur->freq << " )" << endl;
            cur = cur->next;
        }
        cout << endl;
    }
}