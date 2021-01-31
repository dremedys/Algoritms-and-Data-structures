#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n; // число вершин
int MAXN =100;
vector<int> g[100]; // граф
bool used[100];
vector<int> ans;
 
void dfs (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs (to);
	}
	ans.push_back (v);
}
 
void topological_sort() {
	for (int i=0; i<n; ++i)
		used[i] = false;
	ans.clear();
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
	reverse (ans.begin(), ans.end());
}
int main(){
    cin >> n;
    int m;
    cin >> m;
    for(int i = 0 ; i < m ;i++ ){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    topological_sort();
    for(int i = 0 ; i < ans.size() ;i++){
        cout << ans[i] << " ";
    }
}