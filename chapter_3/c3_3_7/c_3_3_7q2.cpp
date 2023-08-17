//
// Created by Hleonor on 2023-08-17.
//
#include <iostream>
#include <stack>
using namespace std;

/**
 * 对问题进行抽象，即对于任意个输入的序列，例如:HHSSHSH
 * 都能将所有的S排到H以前，即得到序列SSSHHHH
 * @return
 */

string dispatch(string train)
{
    stack<char> auxiliary;
    string result;
    for (int i = 0; i < train.size(); i++)
    {
        if (train[i] == 'H') // 硬座
        {
            // 入栈
            auxiliary.push(train[i]);
        }
        else
        {
            result += train[i];
        }
    }
    while (!auxiliary.empty())
    {
        result += auxiliary.top();
        auxiliary.pop();
    }
    return result;
}


int main()
{
    string train;
    cin >> train;
    cout << dispatch(train) << endl;
    return 0;
}
