#include <bits/stdc++.h>
using namespace std;
vector<int> g[100000];
queue<int> q;
int used[100000];

int n, m, x, y;

int bfs(int t) {
    q.push(t);
    int cnt = 1;
    used[t] = true;
    while (!q.empty()) {
        int v = q.front();
        for (int i = 0; i < g[v].size(); i++) {
            int u = g[v][i];
            if (used[u] == false) {
                cnt++;
                used[u] = true;
                q.push(u);
            }
        }
        q.pop();
    }
    return cnt;
}
int main(){
    cin >> n >> m ;
    int maxa = 1000000;
    for(int i =0 ;  i < m ; i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0 ; i < n ; i++){
        if(!used[i]){
            int tmp = bfs(i);
            if(tmp<maxa){
                maxa = tmp;
            }
        }
    }
    cout << maxa ; 
}