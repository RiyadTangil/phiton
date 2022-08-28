#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;
main()
{

       Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(6);
    cout << st.pop() << endl;
    cout << st.empty() << endl;
    cout << st.size() << endl;
    cout << st.Top() << endl;
    cout << "Middle Element : " << st.findMiddle() << endl;
    return 0;
}
