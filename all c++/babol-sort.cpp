// Optimized implementation of Bubble sort
#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)

        cout << " " << arr[i];

    cout << endl;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        cout << i + 1 << "st iteration:" << endl;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
            cout << j + 1 << "st step ";
            printArray(arr, n);
        }

        // IF no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

// Function to print an array

// Driver program to test above functions
int main()
{
    int arr[] = {7, 2, 13, 2, 11, 4};
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);

    return 0;




}
// This code is contributed by shivanisinghss2110
