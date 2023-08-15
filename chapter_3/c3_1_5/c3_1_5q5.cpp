//
// Created by Hleonor on 2023-08-15.
//
#include <iostream>
using namespace std;

class share_stack
{
public:
    int value[20];
    int maxSize = 20;
    int left = -1;
    int right = maxSize;

    int push_left(int x)
    {
        if (right - left == 1)
        {
            cout << "Stack is full, insert failed!" << endl;
            return -1;
        }
        value[++left] = x;
        return x;
    }

    int push_right(int x)
    {
        if (right - left == 1)
        {
            cout << "Stack is full, insert failed!" << endl;
            return -1;
        }
        value[--right] = x;
        return x;
    }

    int pop_left()
    {
        if (left == -1)
        {
            cout << "Stack is empty, pop failed!" << endl;
            return -1;
        }
        int x = value[left--];
        return x;
    }

    int pop_right()
    {
        if (right == maxSize)
        {
            cout << "Stack is empty, pop failed!" << endl;
            return -1;
        }
        int x = value[right--];
        return x;
    }

    bool isEmpty()
    {
        if (left == -1 && right == maxSize)
        {
            return true;
        }
        return false;
    }
};


int main()
{
    share_stack myStack;
    cout << myStack.push_left(1) << endl;
    cout << myStack.push_left(2) << endl;
    cout << myStack.push_left(3) << endl;
    cout << myStack.push_left(4) << endl;
    cout << myStack.push_left(5) << endl;
    cout << myStack.push_right(6) << endl;
    cout << myStack.push_right(7) << endl;
    cout << myStack.push_right(8) << endl;
    cout << myStack.push_left(9) << endl;
    cout << myStack.push_left(10) << endl;
    cout << myStack.push_left(11) << endl;
    cout << myStack.push_left(12) << endl;
    cout << myStack.push_left(13) << endl;
    cout << myStack.push_right(14) << endl;
    cout << myStack.push_right(15) << endl;
    cout << myStack.push_right(16) << endl;
    cout << myStack.push_right(17) << endl;
    cout << myStack.push_right(18) << endl;
    cout << myStack.push_right(19) << endl;
    cout << myStack.push_right(20) << endl;
    cout << myStack.push_right(21) << endl;

    return 0;
}