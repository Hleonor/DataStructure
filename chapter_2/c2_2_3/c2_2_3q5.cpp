//
// Created by Hleonor on 2023-08-09.
//
#include <iostream>
using namespace std;

// 这题和第三题的思想一样，都是原地删除满足条件的元素
void delete_between_s_and_t(int *array, int *length, int s, int t)
{
    if (s >= t || *length == 0)
    {
        cout << "error" << endl;
        return;
    }
    int k = 0; // 记录不在范围[s, t]之间的元素个数
    for (int i = 0; i < *length; i++)
    {
        if (array[i] < s || array[i] > t)
        {
            array[k++] = array[i];
        }
    }
    *length = k;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int length = 7;
    delete_between_s_and_t(array, &length, 3, 5);
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
