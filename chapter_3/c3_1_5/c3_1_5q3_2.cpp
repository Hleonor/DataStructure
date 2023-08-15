//
// Created by Hleonor on 2023-08-15.
//
#include <iostream>
using namespace std;

int main()
{
    string str;
    int i_num = 0;
    bool flag = true;
    while (cin>> str)
    {
        for (char i: str)
        {
            if (i == 'i' || i == 'I')
            {
                i_num++;
            }
            if (i == 'o' || i == 'O')
            {
                if (i_num <= 0)
                {
                    flag = false;
                    break;
                }
                i_num--;
            }
        }
        if (flag && i_num == 0)
        {
            cout << "The string is legal." << endl;
        }
        else
        {
            cout << "The string is illegal." << endl;
        }
        flag = true;
    }
}