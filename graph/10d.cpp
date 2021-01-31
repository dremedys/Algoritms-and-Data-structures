#include <iostream>
#include <vector>
using namespace std;

int n, m;
int cnt = 0;
vector<int> g[100000];
bool used[100000];
vector<int> c;

void dfs(int v)
{
    used[v] = true;
    c.push_back(v);
    for (int i = 0; i < g[v].size(); ++i)
    {
        int s = g[v][i];
        if (!used[s])
            dfs(s);
    }
}

vector<vector<int>> ans()
{
    vector<vector<int>> a;
    for (int i = 0; i < n; ++i)
        if (!used[i])
        {
            c.clear();
            dfs(i);
            vector<int> k;
            for (int j = 0; j < c.size(); j++)
                k.push_back(c[j] + 1);

            a.push_back(k);
        }
    return a;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<vector<int>> l = ans();

    cout << l.size() << "\n";
    
    for (size_t i = 0; i < l.size(); i++)
    {
        cout << l[i].size() << "\n";
        for (int j = 0; j < l[i].size(); j++)
        {
            cout << l[i][j] << " ";
        }
        cout << "\n";
    }
}