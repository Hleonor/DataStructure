//
// Created by Hleonor on 2023-08-17.
//
#include <iostream>
#include <stack>
using namespace std;

class stimulate_queue
{
public:
    stack<int> stack1;
    stack<int> stack2; // 用于出队的栈

    void push(int x)
    {
        stack1.push(x);
        cout << "Push element successfully, the element is：" << x << endl;
    }

    void pop()
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        cout << "Pop element successfully, the element is：" << stack2.top() << endl;
        stack2.pop();
        while (!stack2.empty())
        {
            stack1.push(stack2.top());;
            stack2.pop();
        }
    }
};

int main()
{
    stimulate_queue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();
    return 0;
}
