#include <iostream>
#include <vector>
using namespace std;
int n,m,x,y;
bool used[100];
vector<int> road;
vector<int> g[100];
void dfs(int v)
{
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int s = g[v][i];
        if (!used[s]){
            road.push_back(s);
            dfs(s);
        }
            
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    road.push_back(0);
    dfs(0);
    for(int i = 0 ; i < n ; i++){
        cout << road[i] + 1 << " ";
    }
}