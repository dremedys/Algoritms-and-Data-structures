#include <bits/stdc++.h>
using namespace std;
int g[1000][1000];
int n,q,x,y,z;
bool ok(int a,int b,int c){
    return g[a][b] == 1 && g[a][c] == 1 && g[b][c] == 1;
}
int main(){
    cin >> n >> q;
    vector<bool> ans;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 0 ; i < q ; i++){
        cin >> x >> y >> z;
        x--; y--; z--;
        ans.push_back(ok(x,y,z));
    }
    for(int i = 0 ; i < q ; i++){
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}