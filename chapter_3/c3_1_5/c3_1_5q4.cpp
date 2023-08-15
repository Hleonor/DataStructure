//
// Created by Hleonor on 2023-08-15.
//
#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    char value;
    ListNode* next;
};

bool isSymmetrical(ListNode* head)
{
    int length = 0;
    ListNode* cur = head->next;
    stack<char> myStack;
    while (cur)
    {
        length++;
        cur = cur->next;
    }
    // 先让链表走到一半，然后让后面那一半进栈
    cur = head->next;
    for (int i = 1; i <= length / 2; i++)
    {
        cur = cur->next;
    }
    if (length % 2) // 奇数个元素就多走一步
    {
        cur = cur->next;
    }
    while (cur)
    {
        myStack.push(cur->value);
        cur = cur->next;
    }
    // 判断是否对称
    cur = head->next;
    for (int i = 1; i <= length / 2; i++)
    {
        char ch_1 = cur->value;
        char ch_2 = myStack.top();
        if (ch_1 != ch_2)
        {
            return false;
        }
        cur = cur->next;
        myStack.pop();
    }
    return true;
}

void delete_list(ListNode* head)
{
    ListNode* cur = head->next;
    while (cur)
    {
        ListNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
}

int main()
{
    ListNode* head = new ListNode;
    ListNode* cur = head;
    string str;
    while (cin >> str)
    {
        for (char i: str)
        {
            ListNode *node = new ListNode;
            node->value = i;
            cur->next = node;
            cur = cur->next;
        }
        cur->next = nullptr;
        if (isSymmetrical(head))
        {
            cout << "The string is symmetrical." << endl;
        }
        else
        {
            cout << "The string is not symmetrical." << endl;
        }
        str.clear();
        delete_list(head);
        head->next = nullptr;
        cur = head;
    }
    return 0;
}
