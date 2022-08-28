#include <bits/stdc++.h>
using namespace std;

main()
{

    int size, lgNum = 0;
    cin >> size;
    int fArr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> fArr[i];
        if (lgNum < fArr[i])
            lgNum = fArr[i];
    }
    int size2;
    cin >> size2;
    int sArr[size2];
    for (int i = 0; i < size2; i++)
    {
        cin >> sArr[i];
    }
    int thArr[lgNum + 1] = {0};
    for (int i = 0; i < size2; i++)
    {
        thArr[sArr[i]]++;
    }
    for (int i = 0; i < size; i++)
    {
        if (!thArr[fArr[i]])
            cout << fArr[i] << " ";
        thArr[sArr[i]]++;
    }

    return 0;
}