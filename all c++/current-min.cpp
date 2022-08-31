#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;
int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    Stack<int> st;
    Stack<int> minStack;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (array[i] <= min)
        {
            minStack.push(array[i]);
            min = array[i];
        }
        st.push(array[i]);
    }
    while (!st.empty())
    {
        if (minStack.Top() != st.Top())
        {
            st.pop();
            cout << minStack.Top() << " ";
        }
        else
        {
            cout << minStack.Top() << " ";
            minStack.pop();
            st.pop();
        }
    }
    cout << endl;
    return 0;
}