#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a[100][100];
int dx[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int dy[8] = {1, 1, -1, -1, 2, 2, -2, -2};

queue<pair<int, int>> q;

pair<int, int> c[100][100];
int n;
bool check(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= n && a[x][y] == 0);
}

int main()
{

    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a[x1][y1] = 1;
    c[x1][y1] = make_pair(x1, y1);
    q.push(make_pair(x1, y1));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        for (int i = 0; i < 8; i++)
        { // i = 0, 1, 2, 3, 4, 5, 6, 7
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (check(new_x, new_y))
            { // x = 3, y = 3 => 1, 4
                q.push(make_pair(new_x, new_y));
                a[new_x][new_y] = a[x][y] + 1;
                c[new_x][new_y] = make_pair(x, y);
            }
        }
        q.pop();
    }

    cout << a[x2][y2] - 1 << endl;
    vector<pair<int, int>> result;
    result.push_back(make_pair(x2, y2));
    int x = x2;
    int y = y2;
    while (c[x][y] != make_pair(x, y))
    {
        int new_x = c[x][y].first;  // new_x = 6
        int new_y = c[x][y].second; // new_y = 6
        result.push_back(make_pair(new_x, new_y));
        x = new_x;
        y = new_y;
    }

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i].first << " " << result[i].second << endl;

    return 0;
}