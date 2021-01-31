#include <iostream>
using namespace std;
bool isGood(long long w,long long h,long long n,long long m){
    return (m/w)*(m/h) >= n;
}
int main(){
    long long w,h,n;
    cin>>w>>h>>n;
    long long l=0; // ne vlezet
    long long r= 1;
    while( !isGood(w,h,n,r)){
        r *= 2;  //almost good choice than big number
    } //vlezet (nawi pryamougolniki )
    while(r> l +1){ //while left and right boundaries become neighbors
        long long m= (l+r)/2;
        if(isGood(w,h,n,m)){
            r = m;
        } else{
            l = m;
        }
        
    }
    cout<<r;
}