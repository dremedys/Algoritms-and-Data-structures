#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue <int> q;
    string str;
    int n;
    while(true){
        cin >> str;
        if(str == "push") {
            cin >> n;    q.push(n); 
            cout << "ok" << endl;}
        else if(str == "pop") {
          if(q.empty()) cout<<"error"<<endl;
          else {cout<<q.front()<<endl;
            q.pop();}}
        else if(str == "front") {
          if(q.empty()) cout<<"error"<<endl;
           else cout<<q.front()<<endl;} 
        else if(str == "exit") { 
            cout << "bye"<<endl;    break;}
        else if (str == "size") {
            cout <<q.size()<<endl;}
        else {
            while(!q.empty()){
              q.pop();};
            cout<<"ok"<<endl; }
    }
}