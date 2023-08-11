//
// Created by Hleonor on 2023-08-09.
//
#include <iostream>
using namespace std;

void delete_between_s_t(int *array, int *length, int s, int t)
{
    if (s >= t || *length == 0)
    {
        cout << "s, t不合理或为空表！" << endl;
    }
    int start = 0;
    int end = 0;
    for (int i = 0; i < *length; i++) // 找到[s, t]的起点
    {
        if (array[i] >= s)
        {
            start = i;
            break;
        }
    }
    for (int i = start; i < *length; i++) // 找到[s, t]的终点
    {
        if (array[i] > t)
        {
            end = i;
            break;
        }
    }
    for (int i = 0; i < *length - end; i++)
    {
        array[start + i] = array[end + i];
    }
    *length = *length - (end - start);
}

int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 6, 7, 8, 9}, length = 10;
    delete_between_s_t(array, &length, 3, 6);
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}