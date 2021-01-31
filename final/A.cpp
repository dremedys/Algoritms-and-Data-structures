#include <bits/stdc++.h>
using namespace std;
bool ans(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (st.empty() || st.top() != s[i])
        {
            st.push(s[i]);
        }
        else
        {
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    string s;
    cin >> s;
    if (ans(s))
        cout << "YES";
    else
    {
        cout << "NO";
    }
}