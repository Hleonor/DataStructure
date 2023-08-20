//
// Created by Hleonor on 2023-08-20.
//
#include <iostream>
using namespace std;

int simple_match(string main_str, string pattern)
{
    int i = 0, j = 0;
    while (i < main_str.size() && j < pattern.size())
    {
        if (main_str[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1; // 由于下标是从0开始的，所以不同于课本上的从+2
            j = 0;
        }
    }
    if (i == main_str.size())
    {
        cout << "match failed." << endl;
        return -1;
    }
    else
    {
        cout << "match successfully, the index is: " << i - j;
        return i - j;
    }
}

int main()
{
    string str_1, str_2;
    cin >> str_1;
    cin >> str_2;
    simple_match(str_1, str_2);
    return 0;
}
