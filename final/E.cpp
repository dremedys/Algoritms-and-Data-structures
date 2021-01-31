#include <iostream>
#include <cmath>
#include <vector>
#include<stack>
using namespace std;
bool used[10000000];
vector<pair<int,int> > v;
void dfs(int k,int mid) {
    used[k] = true;
    for (int i = 0; i < v.size(); ++i){
        if(abs(v[i].first-v[k].first) + abs(v[i].second-v[k].second) <= mid && !used[i]){
            dfs(i,mid);
        }
    }
    

    //orders
    // schduke
    // 3-4
    //
}
bool good(int mid){
     for(int i = 0 ; i< 10000000;i++)
        used[i]=false;
    dfs(0,mid);
    if(used[v.size()-1])
        return true;
    return false;
   

}

int main() {
    int n;
    cin >> n ;
    
    for(int i = 0; i < n ; i++){
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    
    int left = -1, right = 100000000;
    while(left + 1 < right){
        int mid = (left+right)/2;
        if(good(mid)){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    cout << right;
    return 0;
}