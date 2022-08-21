#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Before sort" << endl;
    printArray(arr, size);
    for (int i = 0; i < size; i++)
    {
        int key = arr[i];//3
        cout<<endl<<"I=>"<<i<<" key =>"<<key<<endl;
        int j = i - 1; //array[j]=5
        while (arr[j] > key && j >= 0)
        {
            //[173]
            arr[j + 1] = arr[j];
            //[177]
            printArray(arr, size);
            j--;
        }
        //[137]
        arr[j + 1] = key;
        printArray(arr, size);
    }
    cout << "After  sorting" << endl;
    printArray(arr, size);
}
