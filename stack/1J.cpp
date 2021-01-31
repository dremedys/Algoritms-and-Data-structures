#include <iostream>
using namespace std;
int gcd(int a, int b)
{   
    while (a!=b) {
        if (a>b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main()
{
    
    int x, y;
   
    cin>>x>>y;
    cout<<gcd(x, y) ;

    return 0;
}