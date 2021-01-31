#include <iostream>
#include <queue>
using namespace std;
int main() {
    deque <int> d;
    string str;
    int n;
    while(true){
        cin >> str;
        if(str == "push_front") {
            cin >> n;
            d.push_front(n); 
            cout << "ok" << endl;}
        else if(str == "push_back") {
            cin >> n;
            d.push_back(n); 
            cout << "ok" << endl;}
        else if(str == "pop_front") {
          if(d.empty()) cout<<"error"<<endl;
          else {cout<<d.front()<<endl;
            d.pop_front();} }
        else if(str == "pop_back") {
          if(d.empty()) cout<<"error"<<endl;
          else {cout<<d.back()<<endl;
            d.pop_back();} }
        else if(str == "front") {
          if(d.empty()) cout<<"error"<<endl;
           else cout<<d.front()<<endl;} 
        else if(str == "back") {
          if(d.empty()) cout<<"error"<<endl;
           else cout<<d.back()<<endl;} 
        else if(str == "exit") { 
            cout << "bye"<<endl;
            break;}
        else if (str == "size") {
            cout <<d.size()<<endl;}
        else {
            while(!d.empty()){
              d.pop_back();};
            cout<<"ok"<<endl; }
    }}