#include <queue>
#include <iostream>
using namespace std;
int main(){
    int cnt=0;
    deque <int> birinwi;
    deque <int> ekinwi;
    for(int i=0;i<5;i++) {
        int n;
        cin>>n;
        birinwi.push_back(n);
    }
    for(int i=0;i<5;i++) {
        int n;
        cin>>n;
        ekinwi.push_back(n);
    }
    
    while( !birinwi.empty()  and !ekinwi.empty() ){
        if (cnt>1000000){
            cout<<"botva"<<endl;
            break;
        }
        else if(birinwi.front()==0 && ekinwi.front()==9){
            birinwi.push_back(birinwi.front());
            birinwi.pop_front();
            birinwi.push_back(ekinwi.front());
            ekinwi.pop_front();
            cnt++;
        }
        else if(birinwi.front()==9 && ekinwi.front()==0){
            ekinwi.push_back(birinwi.front());
            birinwi.pop_front();
            ekinwi.push_back(ekinwi.front());
            ekinwi.pop_front();
            cnt++;
        }
        else if(birinwi.front()<ekinwi.front()){
            ekinwi.push_back(birinwi.front());
            birinwi.pop_front();
            ekinwi.push_back(ekinwi.front());
            ekinwi.pop_front();
            cnt++;
        }
        else {
            birinwi.push_back(birinwi.front());
            birinwi.pop_front();
            birinwi.push_back(ekinwi.front());
            ekinwi.pop_front();
            cnt++;
        }
        
    }
    if(birinwi.empty()==true) cout<<"second "<<cnt<<endl;
    if(ekinwi.empty()==true) cout<<"first "<<cnt<<endl;
    
}