//
// Created by Hleonor on 2023-08-17.
//
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int> converse_queue(stack<int> myStack, queue<int> myQueue)
{
    while (!myQueue.empty())
    {
        myStack.push(myQueue.front());
        myQueue.pop();
    }
    while (!myStack.empty())
    {
        myQueue.push(myStack.top());
        myStack.pop();
    }
    return myQueue;
}

int main()
{
    stack<int> myStack;
    queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue = converse_queue(myStack, myQueue);
    while (!myQueue.empty())
    {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    return 0;
}