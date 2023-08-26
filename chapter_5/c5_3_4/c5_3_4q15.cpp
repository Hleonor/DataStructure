//
// Created by Mocshere on 2023-08-23.
//
#include "chapter5_header.h"

void get_post_traversal(string pre)
{
    if (pre.size() == 1)
    {
        cout << pre << " ";
    }
    else
    {
        char root = pre[0];
        int size = (int)(pre.size() - 1) / 2;
        string left = pre.substr(1, size);
        string right = pre.substr(size + 1, size);
        get_post_traversal(left);
        get_post_traversal(right);
        cout << root << " ";
    }
}

int main()
{
    string pre;
    cout << "Please input the pre sequence: " << endl;
    cin >> pre;
    get_post_traversal(pre);

    return 0;
}