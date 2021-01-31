#include <iostream>
using namespace std;
int main()
{
    int cnt=0,n, middle=1;
    cin>>n;
    while(middle<n){
        middle*=2;
        cnt++;
    }
    cout<<cnt;  
}
