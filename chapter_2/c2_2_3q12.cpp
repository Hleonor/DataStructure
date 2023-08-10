//
// Created by Hleonor on 2023-08-10.
//
#include <iostream>
using namespace std;

/*
 * 首先理解题干的意思，三月份第一次看这道题的时候没有看懂，以为要连着m个元素都相等才能叫主元素
 * 但是其实不需要元素之间是相连的，只要数组中某些相同元素的个数超过数组长度的一半时则认为该元素为数组的主元素
 */

// 时间复杂度和空间复杂度都是O(n)的做法
int find_main_ele(int* list, int* length)
{
    int cnt = 0;
    int number = list[0];
    for (int i = 1; i < *length; i++)
    {
        if (list[i] == number)
        {
            cnt++;
        }
        else
        {
            if (cnt > 0)
            {
                cnt--;
            }
            else
            {
                number = list[i];
            }
        }
    }
    cnt = 0;
    for (int i = 0; i < *length; i++)
    {
        if (list[i] == number)
        {
            cnt++;
        }
    }
    if (cnt > *length / 2)
    {
        return number;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int list[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int length = sizeof(list) / sizeof(int);
    int main_ele = find_main_ele(list, &length);
    if (main_ele != -1)
    {
        cout << "The main element is " << main_ele << endl;
    }
    else
    {
        cout << "There is no main element in the array" << endl;
    }
    return 0;
}