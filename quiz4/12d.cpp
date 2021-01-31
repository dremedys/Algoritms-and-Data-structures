#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, m, x, y;
vector<int> g[100000];
bool used[100000];
vector<int> ans;
using namespace std;
void dfs(int v)
{
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int s = g[v][i];
        if (!used[s])
            dfs(s);
    }
    ans.push_back(v);
}
void topological_sort()
{
    for (int i = 0; i < n; ++i)
        used[i] = false;
    ans.clear();
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs(i);
    reverse(ans.begin(), ans.end());
}
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
    }
    topological_sort();
    for(int i = 0 ; i < ans.size() ;i++){
        cout << ans[i] + 1 << " ";
    }
}