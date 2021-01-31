#include <bits/stdc++.h>
using namespace std;

int ans(vector<int>& a){
    if(a.size() == 1 ) 
        return abs(a[0]);

    vector<int> sums(a.size()+1);
    long long mini = 1e20;
    sums[0]=0;
        
    for(int i = 0 ; i < a.size();i++){
        sums[i+1] = a[i] + sums[i];
    }
    sort(sums.begin(),sums.end());

    for(int i = 1 ; i < sums.size();i++){
        if(abs(sums[i]-sums[i-1])<mini){
            mini = abs(sums[i]-sums[i-1]);
        }
    }
    return mini;
}
int main(){
    int n;
    cin >> n;
    vector<int> a;
    int cnt= 0;
    for(int i = 0 ;i < n ;i++){
        int x;
        cin >>x;
        a.push_back(x);
        
    }
    cout << ans(a);
    
}