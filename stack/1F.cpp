#include <iostream>
#include <stack>
using namespace std;
bool right( string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else {
            if ( st.empty()==true)
                return false;
            if (st.top()== '(' && s[i] != ')')
                return false;
            
            if (st.top()== '{' && s[i] != '}')
                return false;
            if (st.top()== '[' && s[i] != ']')
                return false;
            st.pop();
        } 
    }

    if (st.empty()==true )
       return true;
    return false;
    
}
int main() {
    string s;
    cin >> s;
    if ( right(s)==true)
        cout << "yes";
    else
    {
        cout << "no";
    }
    
    
}