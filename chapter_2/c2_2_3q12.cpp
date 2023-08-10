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
    int result = -1;
    /*int* bucket = new int(*length);*/
    int bucket[100] = {0};
    for (int i = 0; i < *length; i++)
    {
        bucket[list[i]]++;
    }
    int criticalValue = *length / 2;
    for (int i = 0; i < *length; i++)
    {
        if (bucket[i] > criticalValue)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int length;
    cin >> length;
    int* list_1 = new int(length);
    for (int i = 0; i < length; i++)
    {
        cin >> list_1[i];
    }
    int result = find_main_ele(list_1, &length);
    if (result == -1)
    {
        cout << "No main element" << endl;
    }
    else
    {
        cout << result << endl;
    }
    return 0;
}