#include <stdio.h>
void makeNArray(int n, int squares[])
{
    int new_array[n];
    for (int i = 0; i < n; i++)
    {
        squares[i] = squares[i] * squares[i];
    }
}
int main()
{
    int array[] = {1, 2, 3, 4};
    size_t n = sizeof(array) / sizeof(array)[0];
    makeNArray(n, array);
    return 0;
}
