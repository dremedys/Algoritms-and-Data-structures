#include <iostream>
#include <stack>

using namespace std;
bool opened[26];
bool is_ok(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if( !opened[s[i]-'a']){
            st.push(s[i]);
            opened[s[i]-'a'] = true;
        }
        else { //every opened letter must be closed
            if (st.empty())
                return false;
            char ch = st.top();
            if(ch != s[i])
                return false;
            opened[ch-'a'] = false;
            st.pop();
        } 
    }
    for(int i = 0; i < 26;i++){
        if(opened[i]){
            return false;
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    if (is_ok(s))
        cout << "YES";
    else
    {
        cout << "NO";
    }
    
    return 0;
}