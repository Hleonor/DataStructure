//
// Created by Hleonor on 2023-08-16.
//
#include <iostream>
using namespace std;

class MyQueue
{
public: // 实际应用中这些成员变量都应该设置为private
    int tag = false;
    int front = 0;
    int rear = 0;
    int maxSize = 10;
    int* queue = nullptr;
    MyQueue(int maxSize)
    {
        this->maxSize = maxSize;
        queue = new int(this->maxSize);
    };

    int push(int x)
    {
        if (tag == 1 && this->rear == this->front)
        {
            cout << "The queue is full already, can't be pushed new elements." << endl;
            return -1;
        }
        tag = 1;
        queue[(this->rear++) % maxSize] = x; // 指针先后移再插入元素
        cout << "push value: " << x << endl;
        return x;
    }

    int pop()
    {
        if (tag == 0 && this->rear == this->front)
        {
            cout << "The queue is empty already, can't pop any elements." << endl;
            return -1;
        }
        tag = 0;
        int x = queue[(this->front++) % maxSize];
        cout << "pop value: " << x << endl;
        return x;
    }

    bool isEmpty()
    {
        return getCurrentSize() == 0;
    }

    int getCurrentSize() const
    {
        return (this->rear - this->front + maxSize) % maxSize;
    }
};

int main()
{
    MyQueue queue(10);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.push(7);
    queue.push(8);
    queue.push(9);
    queue.push(10);
    queue.push(11);
    queue.push(12);
    queue.push(13);

    return 0;
}