#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
}
void subTest(int testArraySize, int arr[]) // 78 1 22 12 3
{
    for (int j = 0; j < testArraySize; j++) // 5
    {
        int idxOne, idxTwo, minValue;
        cin >> idxOne >> idxTwo; // 1 2

        minValue = arr[idxOne - 1]; // 78
        for (int i = idxOne-1; i <= idxTwo-1; i++)
        {
            int currentValue = arr[i];
            if (currentValue < minValue)
            {
                minValue = currentValue;
            }
        }

               cout << minValue << endl; // 1
    }
}

void equalTest(int size, int arr[])
{
    int resArray[1001] = {0};
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
void maximumFinder(int size, int arr[])
{
    int resArray[101] = {0};
    int mchValue, mchTimes = 1, smallNumber = arr[0];

    for (int i = 0; i < size; i++)
    {
        resArray[arr[i]]++;
        if (arr[i] < smallNumber)
            smallNumber = arr[i];
    }
    const int noOfSmall = resArray[smallNumber];
    cout << size - noOfSmall << endl;
}
void depositBalance(int arr[])
{
    int idx;
    cin >> idx;
    cout << arr[idx] << endl;
    arr[idx] = 0;
}
void addMoney(int arr[])
{
    int idx, money;
    cin >> idx >> money;
    arr[idx] = arr[idx] + money;
}
void checkTotal(int arr[])
{
    int startIdx, endIdx, total = 0;
    cin >> startIdx >> endIdx;
    for (int i = startIdx; i <= endIdx; i++)
    {
        int curentValue = arr[i];
        total = total + curentValue;
    }
    cout << total << endl;
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
    int testCase;
    cin >> testCase; // 2
    for (int i = 0; i < testCase; i++)
    {

        int arrSize, testArraySize;      // 5 3
        cin >> arrSize >> testArraySize; // 5 3
        int arr[arrSize];                // 5
        for (int i = 0; i < arrSize; i++)
        {
            cin >> arr[i]; // 78 1 22 12 3
        }
        cout << "Case " << i + 1 << ":" << endl; // Case 1:
        subTest(testArraySize, arr);
    }
    //......................problem-3/C..............
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
    //     }
    //     maximumFinder(arrSize, arr);
    // }

    //.....................problem 5/E............

    // int testCase;
    // cin >> testCase;
    // for (int i = 0; i < testCase; i++)
    // {
    //     int arrSize, selectionTimes;
    //     cin >> arrSize >> selectionTimes;
    //     int arr[arrSize];
    //     for (int i = 0; i < arrSize; i++)
    //     {
    //         cin >> arr[i];
    //     }
    //       cout << "Case " << testCase << ":" << endl;
    //     for (int i = 0; i < selectionTimes; i++)
    //     {
    //         int option;

    //         cin >> option;
    //         if (option == 1)
    //         {
    //             depositBalance(arr);
    //         }
    //         else if (option == 2)
    //         {
    //             addMoney(arr);
    //         }
    //         else
    //         {
    //             checkTotal(arr);
    //         }

    //     }
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
    //     }
    //     equalTest(arrSize, arr);
    // }
    //......................problem-6/F..............

    // int arr[3], difCol[101] = {0};

    // for (int i = 0; i < 3; i++)
    // {
    //     cin >> arr[i];
    //     difCol[arr[i]]++;
    // }
    // int difColor = 0, iterate = 0;

    // for (int i = 0; i < 101; i++)
    // {
    //     if (difCol[i] == 0)
    //         continue;
    //     else
    //     {
    //         if (iterate == 3)
    //             break;
    //         difColor++;
    //         iterate++;
    //     }
    //     difCol[i];
    // }
    // cout << difColor;

    //        difCol++;

    //......................problem-7/G..............

    // int num;
    // cin >> num;

    // if (num > 99 && num % 10 == num / 100)
    // {
    //     cout << "Yes";

    // }
    // else if (num < 99 && num % 10 == num / 10)
    // {

    //     cout << "Yes";

    // }
    // else
    // {
    //     cout << "No";

    // }
    //......................problem-8/H..............
    // string str;
    // int characters = 0, startCount = 0, Apossitions=0, Zpositions=0;
    // cin >> str;

    // for (int i = 0; i < str.length(); i++)
    // {

    //     if (str[i] == 'A')
    //     {
    //         Apossitions = i;

    //         break;
    //     }
    // }
    // for (int i = str.length(); i >= 0; i--)
    // {

    //     if (str[i] == 'Z')
    //     {
    //         Zpositions =i;

    //         break;
    //     }
    // }
    // cout <<  Zpositions+1 - Apossitions << endl;

    return 0;
}
