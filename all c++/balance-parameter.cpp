#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;
bool balanceParenthesis(string s)
{
    int n = s.size();
    Stack<char> st;
    bool isBoolean = true;
    if (s[0] == ')' || s[0] == '}' || s[0] == ']')
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        // opening Bracket;
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.Top() == '(')
                st.pop();
            else
            {
                isBoolean = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (st.Top() == '{')
                st.pop();
            else
            {
                isBoolean = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (st.Top() == '[')
                st.pop();
            else
            {
                isBoolean = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        isBoolean = false;
    }
    return isBoolean;
}
int main()
{
    string chk;
    cin >> chk;
    if (balanceParenthesis(chk))
    {
        cout << "YES";
    }
    else
        cout << "NO";

    cout << endl;
    return 0;
}