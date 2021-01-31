#include <iostream>
#include <stack>
#include <cstring> 
using namespace std;

bool isDigit(char a){
    if (a>='0' and a<= '9')
        return true;
    return false;
}

int main(){
    string s;
    stack<int> st;
    int x=0;
    while(x==0){   //stupid way to read one line
        getline(cin,s);
        x=1;
    }
    for(int i = 0; i < s.length() ; i++){
        
        if( isDigit(s[i]) ){
            
            int n = int(s[i])-48;   
            st.push(n);
            
        }
        else if( s[i] == '+'){
            int B= st.top();
            st.pop();
            int A=st.top();
            st.pop();
            st.push(A+B);
        }
        else if( s[i] == '-'){
            int B= st.top();
            st.pop();
            int A=st.top();
            st.pop();
            st.push(A-B);
        }
        else if( s[i] == '*'){
            int B= st.top();
            st.pop();
            int A=st.top();
            st.pop();
            st.push(A*B);
        }
    }
    cout<<st.top();
}