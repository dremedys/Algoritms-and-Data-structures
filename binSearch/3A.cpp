#include <iostream>

using namespace std;

int main()
{
    int N ;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++) cin>>A[i];
    int x;
    cin >> x;
    for(int i=0;i<N;i++){
        if (A[i]==x){
            cout<<i+1<<" ";
        }
    }

    return 0;
}
