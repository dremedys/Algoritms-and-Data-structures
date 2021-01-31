
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int g[1000][1000];
bool used[1000];
int cnt = 0 ;
int n,m,q,x,y;

int bfs(int v,int cnt){
	used[v] = true;
	for (int i = 0; i < n; ++i)
        {
            if (g[v][i] != 0 && (!used[i]))
            {
                cnt--;
                used[i] = true;
            }
        }
	return cnt;
}
int main() {
	cin >> n >> m >> q;
	int lol[q];
	int ans[q];
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> g[i][j];
			if(g[i][j]) cnt++;
		}
	}
	for(int i = 0 ; i < q ; i++){
		cin >> lol[i];
		ans[i] = bfs(lol[i],cnt);
	}
	for(int i = 0 ; i < q ; i++){
		cout << ans[i] << "\n";
	}
}

