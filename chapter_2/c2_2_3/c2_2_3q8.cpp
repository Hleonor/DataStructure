//
// Created by Hleonor on 2023-08-10.
//
#include <iostream>
using namespace std;

void switch_2_array(int* list, int* m, int* n)
{
    for (int i = *m; i < *m + *n; i++)
    {
        // 不管怎么样，后面n个元素都是往前面走m步
        int j = i;
        int cnt = 0;
        while (cnt < *m) // 由于是走m个单位，所以不是下标
        {
            int tmp = list[j];
            list[j] = list[j - 1];
            list[j - 1] = tmp;
            cnt++;
            j--;
        }
    }
}

int main()
{
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int m = 3, n = 5;

    switch_2_array(list, &m, &n);
    for (int i = 0; i < m + n; i++)
    {
        cout << list[i] << " ";
    }
    return 0;
}