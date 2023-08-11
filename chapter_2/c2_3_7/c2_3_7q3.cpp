//
// Created by Hleonor on 2023-08-11.
//
#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int number;
    int value;
    ListNode *next;
};

void reverse_output_list(ListNode* head)
{
    stack<ListNode*> my_stack;
    ListNode* current_node = head;
    while (current_node)
    {
        my_stack.push(current_node);
        current_node = current_node->next;
    }
    while (!my_stack.empty())
    {
        ListNode* node = my_stack.top();
        cout << node->value << " ";
        my_stack.pop();
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
    reverse_output_list(head->next);
    return 0;
}