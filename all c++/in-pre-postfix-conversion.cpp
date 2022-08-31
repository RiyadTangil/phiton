#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;
int precisionCalc(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPrefix(string chk)
{
    reverse(chk.begin(), chk.end());
    cout << "revested=> " << chk << endl;

    Stack<char> st;
    string result;
    for (int i = 0; i < chk.length(); i++)
    {
        //   string infix = "(7+(4+5))-(2+0)";
        //   string infix = " )0+2(-))5+4(+7(";
        if (chk[i] >= '0' && chk[i] <= '9')
            result += chk[i];
        else if (chk[i] == ')')
            st.push(chk[i]);
        else if (chk[i] == '(')
        {
            while (!st.empty() && st.Top() != ')')
            {
                result += st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            // joto khon current value top theke boro na  hoy toto khon pop koro
            while (!st.empty() && precisionCalc(st.Top()) >= precisionCalc(chk[i]))
            {
                result += st.pop();
            }
            st.push(chk[i]); //1=> ) => + =>
        }
    }
    while (!st.empty())
    {
        result += st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
int prefixEvaluation(string chk)
{
    Stack<int> st;
    for (int i = chk.length() - 1; i >= 0; i--)
    {
        if (chk[i] >= '0' && chk[i] <= '9')
        {
            st.push(chk[i] - '0');
        }
        else
        {
            int a = st.pop();
            int b = st.pop();
            switch (chk[i])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '^':
                st.push(pow(a, b));
                break;
            default:
                break;
            }
        }
    }
    return st.Top();
}
main()
{
    string infix = "(7+(4+5))-(2+0)"; 
    // The prefix form of the expression (A + B) * (C + D) is:
    //                                      (+AB)*(+CD)
    //                                      *+AB+CD)

    // The postfix form of the expression (A + B) * (C + D) is:
    //                                      (AB+)*(CD+)
    //                                      AB+CD+*
    
    string prefix;
    prefix = infixToPrefix(infix);
    cout << endl
         << infixToPrefix(infix) << "=>" << prefix << endl
         << prefixEvaluation("+9*3/84") << endl;
    // return 0;"+*423"
}