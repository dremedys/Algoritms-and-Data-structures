#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int n;
int x1, x2, y1, y2;
int dis[100][100];
int dx[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int dy[8] = {1, 1, -1, -1, 2, 2, -2, -2};
pair<int, int> parent[100][100];
bool isIn(int x, int y)
{
    return (x >= 1 && y >= 1 && x <= n && y <= n && dis[x][y] == 0);
}

int main()
{
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    dis[x1][y1] = 1;
    parent[x1][y1] = make_pair(-1, -1);
    q.push(make_pair(x1, y1));

    while (!(q.empty()))
    {
        int x = q.front().first;
        int y = q.front().second;
        for (int i = 0; i < 8; i++)
        {
            int cur_x = x + dx[i];
            int cur_y = y + dy[i];
            if (isIn(cur_x, cur_y))
            {
                q.push(make_pair(cur_x, cur_y));
                dis[cur_x][cur_y] = dis[x][y] + 1;
                parent[cur_x][cur_y] = make_pair(x, y);
            }
        }
        q.pop();
    }
    cout << dis[x2][y2] - 1 << " \n";
    vector<pair<int, int>> path;
    for (pair<int, int> pos = make_pair(x2, y2); pos != make_pair(-1, -1); pos = parent[pos.first][pos.second])
    {
        path.push_back(make_pair(pos.first, pos.second));
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i].first << " " << path[i].second << "\n";
    }
}