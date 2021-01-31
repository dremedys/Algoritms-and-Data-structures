#include <bits/stdc++.h>
using namespace std;
bool used[30000];
int dis[30000];
int parent[30000];
int main(){
    int x,y;
    cin >> x >>y;
    queue<int> q;
    q.push(x);
    used[x] = true;
    parent[x] = -1;
    dis[x]=1;
    while(!q.empty()){
        int n = q.front();
        if(n==y) break;
        q.pop();
        if(!used[n*2] && n<y){
            q.push(n*2);
            used[n*2]=true;
            dis[n*2] = dis[n]+1;
            parent[n*2] = n;
            if(n*2==y){
                break;
            }
        }
        if(!used[n-1] && n>0){
            q.push(n-1);
            used[n-1]=true;
            dis[n-1] = dis[n]+1;
            parent[n-1] = n;
            if(n-1==y)
                break;
        }
        
    }
    cout << dis[y] - 1 << "\n";
    vector<int> path;
    for(int i = y ; i != -1; i = parent[i]){
        path.push_back(i);
    }
    if(path.size()){
        reverse(path.begin(), path.end());
    
    for (int i = 1; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    }
    
}