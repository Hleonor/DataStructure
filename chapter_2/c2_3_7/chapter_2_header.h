//
// Created by Hleonor on 2023-08-12.
//

#ifndef DATASTRUCTURE_CHAPTER_2_HEADER_H
#define DATASTRUCTURE_CHAPTER_2_HEADER_H

struct ListNode
{
    int number;
    int value;
    ListNode *next;
};

void output_list(ListNode* head)
{
    ListNode* current_node = head->next;
    while (current_node)
    {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
}

ListNode* build_list()
{
    ListNode* head = new ListNode;
    head->value = INT_MIN;
    head->number = 0;
    head->next = nullptr;
    ListNode *currentNode = head;
    for (int i = 1; i <= 10; i++)
    {
        ListNode *next = new ListNode;
        next->value = i;
        next->number = i;
        next->next = nullptr;
        currentNode->next = next;
        currentNode = next;
    }
}
#endif //DATASTRUCTURE_CHAPTER_2_HEADER_H
