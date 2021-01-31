#include <iostream>

using namespace std;

int main()
{
    int N ;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++) cin>>A[i];
    int maxind=0;
    for(int i=1;i<N;i++){
        if (A[i]>A[maxind]){
            maxind=i;
        }
    }
    cout<<maxind+1;
    return 0;
}
