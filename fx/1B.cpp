#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool possible(vector<int> &packs, int H, int K)
{
    int time = 0;
   
    for(int i = 0; i < packs.size();i++){
        time += (packs[i]-1)/K + 1;
    }
    return time <= H;
}

int minEatingSpeed(vector<int> &packs, int H)
{
    int lo = 1, hi = pow(10, 9);
    while (lo < hi)
    {
        int mi = lo + (hi - lo) / 2;
        if (!possible(packs, H, mi))
            lo = mi + 1;
        else
            hi = mi;
    }

    return lo;
}
int main(){
    int n,m;
    vector<int> a;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >>x ;
        a.push_back(x);
    }
    cout << minEatingSpeed(a,m);
}