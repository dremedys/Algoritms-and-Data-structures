#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, m, x, y;
vector<int> g[100];
bool used[100];
vector<int> ans;
bool loop = false;
set<pair<int, int>> check;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs2(int v, int par)
{ // passing vertex and its parent vertex
    color[v] = 1;
    for (size_t i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i]; //for (int u : adj[v]) {
        if (u == par)
            continue; // skipping edge to parent vertex
        if (color[u] == 0)
        {
            parent[u] = v;
            if (dfs2(u, parent[u]))
                return true;
        }
        else if (color[u] == 1)
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool find_cycle()
{
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++)
    {
        if (color[v] == 0 && dfs2(v, parent[v]))
            break;
    }

    if (cycle_start == -1)
    {
        return false;
    }
    return true;
}
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
int main()
{
    bool loop = false;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        if (x == y)
        {
            loop = true;
            break;
        }
        if (check.find(make_pair(y, x)) == check.end())
        {
            check.insert(make_pair(x, y));
        }
        else
        {
            loop = true;
            break;
        }
        g[x].push_back(y);
    }
    if (loop)
    {
        cout << "No";
    }
    else
    {
        if (find_cycle())
        {
            cout << "No";
        }
        else
        {
            topological_sort();

            cout << "Yes"
                 << "\n";
            for (int i = 0; i < n; i++)
                cout << ans[i] + 1 << " ";
        }
    }

    return 0;
}