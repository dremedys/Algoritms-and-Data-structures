#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int g[100][100];
queue<int> q;
bool used[100];

int n;

void bfs(int v)
{
    q.push(v);
    used[v] = true;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (int i = 0; i < n; ++i)
        {
            if (g[top][i] != 0 && (!used[i]))
            {
                q.push(i);
                used[i] = true;
            }
        }
    }
}
bool ans(int cnt, int n)
{
    bfs(0);

    if (cnt / 2 + 1 != n)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] == false)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 1)
                cnt++;
        }
    }
    if (ans(cnt, n))
        cout << "YES";
    else
        cout << "NO";
}
