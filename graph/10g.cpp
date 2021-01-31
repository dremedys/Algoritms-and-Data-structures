#include <iostream>
#include <queue>
using namespace std;
int n, m;
char a[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool ok(int x, int y)
{
    if (x >= n || y >= m)
        return false;

    if (x < 0 || y < 0)
        return false;

    return true;
}
void bfs(int x, int y)
{
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));

    while (!q.empty())
    {
        pair<int, int> cur = make_pair(q.front().first, q.front().second);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (ok(x, y) && a[x][y] == '#')
            {
                q.push(make_pair(x, y));
                a[x][y] = '.';
            }
        }
    }
}
int main()
{
    int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#')
            {
                a[i][j] = '.';
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;
}