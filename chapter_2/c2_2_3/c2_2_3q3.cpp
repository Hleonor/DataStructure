//
// Created by Hleonor on 2023-08-09.
//
#include <iostream>
using namespace std;

void delete_x(int* array, int* length, int x)
{
    int k = 0; // 表示不等于x的元素的个数
    for (int i = 0; i < *length; i++)
    {
        if (array[i] != x)
        {
            array[k] = array[i];
            k++;
        }
    }
    *length = k;
}

int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 6, 7, 8, 9}, length = 10;
    delete_x(array, &length, 6);
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}