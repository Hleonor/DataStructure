//
// Created by Hleonor on 2023-08-09.
//

#include <iostream>
using namespace std;

// 只要是需要原地删除数组中的元素，就都可以使用这种方法
void remove_duplicated(int* array, int* length)
{
    int k = 0;
    for (int i = 0; i < *length - 1; i++)
    {
        if (array[i] != array[i + 1])
        {
            array[k++] = array[i];
        }
    }
    *length = k;
}

int main()
{
    int array[] = {1, 2, 2, 3, 3, 3, 4, 5, 6, 6};
    int length = 10;
    remove_duplicated(array, &length);
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
