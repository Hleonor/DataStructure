//
// Created by Hleonor on 2023-08-10.
//
#include <iostream>
using namespace std;

int* find_and_replace(int *list, int *length, int x)
{
    bool flag = false;
    int left = 0, right = *length - 1, middle = 0;
    while (left <= right)
    {
        middle = left + ((right - left) >> 1);
        if (x > list[middle])
        {
            left = middle + 1;
        }
        else if (x < list[middle])
        {
            right = middle - 1;
        }
        else
        {
            flag = true;
            break;
        }
    }
    if (flag) // 如果退出循环的时候仍然满足left <= right，说明元素已经找到了
    {
        if (middle != *length - 1)
        {
            int tmp = list[middle];
            list[middle] = list[middle + 1];
            list[middle + 1] = tmp;

            for (int i = 0; i < *length; i++)
            {
                cout << list[i] << " ";
            }
            cout << endl;
            return list;
        }
        else
        {
            cout << "已经是数组中的最后一个元素，不能再和后继进行交换！" << endl;
            return list;
        }
    }
    else // 否则就是没找到，此时将老的堆区数组复制到一个新的堆区数组中，并且在最后添加一个元素
    {
        int *result = new int(*length + 1);
        for (int i = 0; i <*length; i++)
        {
            result[i] = list[i];
        }
        int i = 0;
        for (i = *length; i > left; i--)
        {
            result[i] = result[i - 1];
        }
        result[i] = x;
        (*length)++;

        for (int i = 0; i < *length; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
        return result;
    }

}

int main()
{
    int list[] = {1, 3, 5, 7, 9};
    int length = 5;
    int x = 4;
    int *result = find_and_replace(list, &length, 9);

    return 0;
}