//
// Created by Hleonor on 2023-08-10.
//
#include <iostream>

using namespace std;

void reverse(int *list, int from, int to)
{
    for (int i = 0; i < ((to - from) + 1) / 2; i++)
    {
        int tmp = list[from + i];
        list[from + i] = list[to - i];
        list[to - i] = tmp;
    }
}

void converse(int *list, int *length, int p)
{
    reverse(list, 0, p - 1);
    reverse(list, p, *length - 1);
    reverse(list, 0, *length - 1);
}


int main()
{
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int length = 8;
    converse(list, &length, 3);
    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
    return 0;
}
