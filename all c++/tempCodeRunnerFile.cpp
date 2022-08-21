#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
}
void subTest(int testArraySize, int arr[])
{
    for (int j = 0; j < testArraySize; j++)
    {
        int idxOne, idxTwo, minValue;
        cin >> idxOne >> idxTwo;

        int idxOneValue = arr[idxOne - 1];
        int idxTwoValue = arr[idxTwo - 1];
        if (idxOneValue < idxTwoValue)
        {
            minValue = idxOneValue;
        }
        else
        {
            minValue = idxTwoValue;
        }
        cout << minValue << endl;
    }
}

void equalTest(int size, int arr[])
{
    int resArray[1000] = {0};
    int mchValue, mchTimes = 1;

    for (int i = 0; i < size; i++)
    {
        resArray[arr[i]]++;
    }

    for (int i = 0; i < size; i++)
    {
        if (resArray[arr[i]] > mchTimes)
        {
            mchTimes = resArray[arr[i]];
            mchValue = arr[i];
        }
    }
    if (mchTimes == 1)
    {
        cout << size - 1 << endl;
    }
    else if (mchTimes == size)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << size - mchTimes << endl;
    }
}

int main()
{

    //......................problem-1..............
    // int arr[4] = {0};
    // int solvedWeeks = 0;
    // for (int i = 0; i < 4; i++)
    // {
    //     cin >> arr[i];
    //     if (arr[i] >= 10)
    //     {
    //         solvedWeeks++;
    //     }
    // }
    // cout<<solvedWeeks;
    // printArray(arr, 4);
    //......................problem-2/B..............
    // int testCase;
    // cin >> testCase;
    // for (int i = 0; i < testCase; i++)
    // {
    //     // cout <<" ";
    //     int arrSize, testArraySize;
    //     cin >> arrSize >> testArraySize;
    //     int arr[arrSize];
    //     for (int i = 0; i < arrSize; i++)
    //     {
    //         cin >> arr[i];
    //     }
    //     cout << "Case " << i + 1 << ":" << endl;
    //     subTest(testArraySize, arr);
    // }
    //......................problem-4/D..............
    // int testCase;
    // cin >> testCase;
    // for (int i = 0; i < testCase; i++)
    // {
    //     // cout <<" ";
    //     int arrSize;
    //     cin >> arrSize;
    //     int arr[arrSize];
    //     for (int i = 0; i < arrSize; i++)
    //     {
    //         cin >> arr[i];
    //     }z
    //     equalTest(arrSize, arr);
    // }
    //......................problem-5/E..............

    int arr[3], difCol[100] = {0};

    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
        difCol[arr[i]]++;
    }
    int difColor = 0, iterate = 0;

    for (int i = 0; i < 100; i++)
    {
        if (difCol[i] == 0)
            continue;
        else
        {
            if (iterate == 3)
                break;
            difColor++;
            iterate++;
        }
        difCol[i];
    }
    cout << difColor;

    //     if (col1 != col2 && col1 != col3 && col2 != col3)
    //     {
    //         difCol = 3;
    //         return;
    //     }
    //    else if (col1 != col2 && col1 != col3 && col2 == col3)
    //     {
    //         difCol = 2;
    //         return;
    //     }
    //    else if (col1 != col2 && col1 != col3 && col2 == col3)
    //     {
    //         difCol = 2;
    //         return;
    //     }

    //     difCol = difCol + 2;
    //     if (col1 == col2 && col1 != col3)
    //         difCol++;
    //     if (col1 != col2 && col1 == col3)
    //         difCol++;
    //     if (col1 != col2 && col1 == col3)
    //         difCol++;

    return 0;
}
