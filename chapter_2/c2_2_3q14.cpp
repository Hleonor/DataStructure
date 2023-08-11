//
// Created by Hleonor on 2023-08-11.
//
#include <iostream>
#include <math.h>
using namespace std;

// 第十四题，同样利好给定数组已经排好序的思想，其次就是根据答案分析的|c - a|
// 每一轮都是固定c，然后想办法找到最小的a，然后在下一轮让a变大，从而可以使得|c - a|最小
// 当某一次循环c被超过时，则由超过的新的数字取代原来c的位置，重复上面的过程直到所有的数组遍历完

bool min_number(int a, int b, int c)
{
    if (a <= b && a <= c)
    {
        return true;
    }
    return false;
}

int find_min_distance(int *list1, int *length1, int *list2, int *length2, int *list3, int *length3)
{
    int i = 0, j = 0, k = 0;
    int result = INT_MAX;
    int distance = 0;
    while (i < *length1 && j < *length2 && k < *length3 && result > 0) // 由于元素分别来自三个数组，所以只有一个数组遍历完，就可以结束循环
    {
        distance = abs(list1[i] - list2[j]) + abs(list1[i] - list3[k]) + abs(list2[j] - list3[k]);
        if (distance <= result)
        {
            result = distance;
        }
        if (min_number(list1[i], list2[j], list3[k]))
        {
            i++;
        }
        if (min_number(list2[j], list1[i], list3[k]))
        {
            j++;
        }
        if (min_number(list3[k], list1[i], list2[j]))
        {
            k++;
        }
    }
    return result;
}

int main()
{
    int list1[] = {-1, 0 , 9};
    int length1 = sizeof(list1) / sizeof(int);
    int list2[] = {-25, -10, 10, 11};
    int length2 = sizeof(list2) / sizeof(int);
    int list3[] = {2, 9, 17, 30, 41};
    int length3 = sizeof(list3) / sizeof(int);
    int result = find_min_distance(list1, &length1, list2, &length2, list3, &length3);
    cout << "The min distance is " << result << endl;
    return 0;
}