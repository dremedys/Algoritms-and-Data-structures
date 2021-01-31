#include <bits/stdc++.h>
using namespace std;
bool ok(string s){
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        if(st.empty()) {
            st.push(s[i]);
            continue;
        }
        if(s[i] == st.top()) 
            st.pop();
        
        else 
            st.push(s[i]);
        
    }
    return st.empty();

}
int main(){
    
    int n;
    int cnt = 0;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        string s;
        cin >>s;
        if(ok(s)) cnt++;
    }
    
    cout << cnt;
    return 0;
}

