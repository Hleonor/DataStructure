//
// Created by Hleonor on 2023-08-10.
//
#include <iostream>

using namespace std;

// 空间复杂度O(n)，其中默认输入的数据范围只能是数组长度
int finMinPositiveNum(int *list, int *length)
{
    int *bucket = new int[*length + 3]();

    int result = 1;
    for (int i = 0; i < *length; i++)
    {
        int current_number = list[i];
        if (list[i] < 0)
        {
            continue;
        }
        else
        {
            bucket[list[i]] = 1;
        }
    }
    for (int i = 1; i < *length + 3; i++)
    {
        if (bucket[i] == 0)
        {
            result = i;
            return result;
        }
    }
    return result;
}

int main()
{
    int list[] = {1, 2, 3};
    int length = sizeof(list) / sizeof(int);
    int result = finMinPositiveNum(list, &length);
    cout << "The min positive number is " << result << endl;
    return 0;
}