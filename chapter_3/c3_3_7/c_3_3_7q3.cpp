//
// Created by Hleonor on 2023-08-17.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int incursion(int n, int x)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2 * x;
    }
    else
    {
        return 2 * x * incursion(n - 1, x) - 2 * (n - 1) * incursion(n - 2, x);
    }
}

int calculate(int n, int x)
{
    int p_n_1 = 1;
    int p_n_2 = 2 * x;
    if (n == 0)
    {
        return p_n_1;
    }
    else if (n == 1)
    {
        return p_n_2;
    }
    else
    {
        int result = 1;
        int cnt = 2;
        while (cnt <= n)
        {
            result = 2 * x * p_n_2 - 2 * (cnt - 1) * p_n_1;
            cnt++;
            p_n_1 = p_n_2;
            p_n_2 = result;
        }
        return result;
    }
}

int main()
{
    int n, x;
    cin >> n >> x;
    cout << "recursive result is: " << incursion(n, x) << endl;
    cout << "iterating result is: " << calculate(n, x) << endl;
    return 0;
}
