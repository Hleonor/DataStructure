//
// Created by Hleonor on 2023-08-09.
//
#include <iostream>
using namespace std;

int delete_min_value(int* array, int* length)
{
    if (length == 0)
    {
        cout << "��գ�" << endl;
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
    cout << "�����СֵΪ:" << delete_min_value(array, &length) << " ��ǰ��Ԫ�ظ���Ϊ��" << length << endl;
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}