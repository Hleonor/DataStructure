//
// Created by Hleonor on 2023-08-09.
//
#include <iostream>
using namespace std;

int* merge_list(int* list_1, int* length_1, int* list_2, int* length_2)
{
    // 由于是数组，所以不可能合并到其中某一个数组里了，只能重新开辟一个新的数组
    int *result = new int(*length_1 + *length_2);
    int k = 0;
    int i = 0;
    int j = 0;
    while (i < *length_1 && j < *length_2)
    {
        if (list_1[i] <= list_2[j])
        {
            result[k++] = list_1[i++];
        }
        else
        {
            result[k++] = list_2[j++];
        }
    }
    while (i < *length_1)
    {
        result[k++] = list_1[i++];
    }
    while (j < *length_2)
    {
        result[k++] = list_2[j++];
    }
    return result;
}

int main()
{
    int list_1[] = {1, 3, 5, 7, 9};
    int list_2[] = {2, 4, 6, 8, 10};
    int length_1 = 5, length_2 = 5;
    int* result = merge_list(list_1, &length_1, list_2, &length_2);
    for (int i = 0; i < length_1 + length_2; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
