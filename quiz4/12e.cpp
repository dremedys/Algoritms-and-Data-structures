#include <bits/stdc++.h>
using namespace std;
vector<int> g[10000];
int d[10000];
int n, m, x, y;
bool used[10000];
vector<int> really[10000];
queue<int> q;
bool rotated = false;

void bfs(int v)
{
    q.push(v);
    d[v] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        
        for (size_t i = 0; i < g[v].size(); ++i)
        {
            int cur = g[v][i];
            if (!used[cur])
            {
                used[cur] = true;
                q.push(cur);
                //rotated = false;
                d[cur] = d[v] + 1;
                bool found = false;
                for (size_t j = 0; j < really[v].size(); j++)
                {
                    if (really[v][j] == cur)
                    {
                        found = true;
                        break;
                    }
                }
               
                 if (!found && rotated == true)
                {
                    d[cur]++;
                    rotated = false;
                }
             
                //  else rotated  = false;
                //  else if(!found && rotated == true) {d[cur]++; rotated=false;}
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
        really[x].push_back(y);
    }

    bfs(n - 1);
    d[0]--;
    cout << d[0];
}