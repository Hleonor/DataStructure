//
// Created by Hleonor on 2023-08-09.
//
#include <iostream>
using namespace std;

int delete_min_value(int* array, int* length)
{
    if (length == 0)
    {
        cout << "表空！" << endl;
        exit(-1);
    }
    int min_value = 0;
    int index = -1;
    for (int i = 0; i < *length; i++)
    {
        if (array[i] <= min_value)
        {
            min_value = array[i];
            index = i;
        }
    }
    array[index] = array[*length - 1];
    (*length)--;
    return min_value;
}
int main()
{
    int length;
    cin >> length;
    int* array = new int(length);
    for (int i = 0; i < length; i++)
    {
        cin >> array[i];
    }
    cout << "表的最小值为:" << delete_min_value(array, &length) << " 当前的元素个数为：" << length << endl;
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}