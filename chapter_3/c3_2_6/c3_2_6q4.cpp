//
// Created by Hleonor on 2023-08-17.
//
#include <iostream>
using namespace std;

struct QueueNode
{
    int value;
    QueueNode* next;
};

class MyQueue
{
public:
    QueueNode* front;
    QueueNode* rear;
    bool book = false;

    void push(int x)
    {
        if (front == nullptr)
        {
            front = new QueueNode;
            front->value = x;
            front->next = front;
            rear = front;
            cout << "Push element successfully, the element is: " << x << endl;
            book = false;
            return;
        }

        if (isEmpty())
        {
            rear = rear->next;
            rear->value = x;
            cout << "Push element successfully, the element is: " << x << endl;
            front = rear;
        }

        if (isFull()) // 此时队满
        {
            // 说明此时队满
            QueueNode* node = new QueueNode;
            node->value = x;
            node->next = front;
            rear->next = node;
            rear = node;
            cout << "Push element successfully, the element is: " << x << endl;
            book = false;
            return;
        }
        rear = rear->next;
        rear->value = x;
        cout << "Push element successfully, the element is: " << x << endl;
        book = false;
    }

    void pop()
    {
        if (isEmpty())
        {
            if (book) // 两节点第一次相遇，输出完了以后队空
            {
                cout << "Pop successfully, the element is: " << front->value << endl;
                book = false;
                return;
            }
            cout << "Pop failed, the queue is empty." << endl;
            return ;
        }
        cout << "Pop successfully, the element is: " << front->value << endl;
        front = front->next;
        if (front == rear) // 两个指针第一次重叠
        {
            book = true;
        }
    }

    bool isEmpty() const
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }

    bool isFull() const
    {
        if (front == rear->next)
        {
            return true;
        }
        return false;
    }
    MyQueue()
    {
        front = nullptr;
        rear = nullptr;
    }
};


int main()
{
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();
    myQueue.push(4);
    myQueue.pop();
    myQueue.pop();
    return 0;
}