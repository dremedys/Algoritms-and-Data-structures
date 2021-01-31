#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100];
int used[100];
int n, m, x, y;
bool ok;
vector<int> ans;
void dfs(int v, int c)
{
    used[v] = c;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (used[u] == 0)
        {
            dfs(u, 3 - c);
        }
        else
        {
            if (used[u] == c)
                ok = false;
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
    }
    ok = true;

    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
            dfs(i, 1);
    }

    if (ok)
    {
        cout << "YES"
             << "\n";
        for (int i = 0; i < n; i++)
        {
            if (used[i] == 1)
            {
                cout << i + 1 << " ";
            }
        }
    }

    else
        cout << "NO";

    return 0;
}