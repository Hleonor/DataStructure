//
// Created by Hleonor on 2023-08-09.
//
#include <iostream>
using namespace std;

void reverse_array(int* array, int* length)
{
    for (int i = 0; i < (*length) / 2; i++)
    {
        int tmp = array[i];
        array[i] = array[*length - 1 - i];
        array[*length - 1 - i] = tmp;
    }
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
    reverse_array(array, &length);
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}