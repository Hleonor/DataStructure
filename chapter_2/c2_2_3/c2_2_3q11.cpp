//
// Created by Hleonor on 2023-08-10.
//
#include <iostream>
using namespace std;

int find_middle_numeber(int *list1, int* length_1, int *list2, int* length_2)
{
    int cnt = 0;
    int i = 0;
    int j = 0;
    int result = 0;
    while (i < *length_1 && j < *length_2)
    {
        if (cnt == *length_1)
        {
            return result;
        }
        if (list1[i] <= list2[j])
        {
            result = list1[i];
            i++;
        }
        else
        {
            result = list2[j];
            j++;
        }
        cnt++;
    }
    return result;
}

int main()
{
    int list_1[] = {11, 13, 15, 17, 19};
    int list_2[] = {2, 4, 6, 8, 20};
    int length_1 = 5, length_2 = 5;
    int result = find_middle_numeber(list_1, &length_1, list_2, &length_2);
    cout << result << endl;
    return 0;
}
