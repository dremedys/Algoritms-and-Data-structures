#include <iostream>
using namespace std;
int left_boundary(int x,int a[],int size)
{
    int left = -1;  
    int right = size;  
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }    
    return left;
}
bool exists(int x,int a[],int size){
    if(a[left_boundary(x,a,size)+1] == x){
        return true;
    }
    return false;
}
int main(){
    int n;
    int k;
    cin>>n>>k;
    int a[n];
    int b[k];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        cin>>b[i];
    }
    for(int i=0;i<k;i++){
        if(exists(b[i],a,n)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}