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

    void push(int x)
    {
        if (front == nullptr)
        {
            front = new QueueNode;
            front->value = x;
            front->next = front;
            rear = front;
            cout << "Push element successfully, the element is: " << x << endl;
            return;
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
            return;
        }
        rear = rear->next;
        rear->value = x;
        cout << "Push element successfully, the element is: " << x << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Pop failed, the queue is empty." << endl;
            return ;
        }
        cout << "Pop successfully, the element is: " << front->value << endl;
        front = front->next;
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
    myQueue.pop();
    return 0;
}