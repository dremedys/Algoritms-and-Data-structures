#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int maxi=0;
    int sec_max=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>maxi){
            maxi=a[i];
        }}
    for(int i=0;i<n;i++){
        if(a[i]>sec_max and a[i]<maxi){
            sec_max=a[i];
        }
    }
    cout<<sec_max;
}