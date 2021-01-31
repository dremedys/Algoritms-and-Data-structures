#include <bits/stdc++.h>
using namespace std;
int g[1000][1000];
queue<pair<int, int> > q;
int cnt = 0;
int n, m;
bool left(int i, int j)
{
    j--;
    return j >= 0 && g[i][j] == 1;
}
bool right(int i, int j)
{
    j++;
    return j < m && g[i][j] == 1;
}
bool up(int i, int j)
{
    i--;
    return i >= 0 && g[i][j] == 1;
}
bool down(int i, int j)
{
    i++;
    return i < n && g[i][j] == 1;
}
int main()
{
    int k = 0;
    int re = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 1)
            {
                cnt++;
            }
            else if (g[i][j] == 2)
            {
                q.push(make_pair(i,j));
            }
        }
    }
    int d[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            d[i][j] = 0;
        }
    }
  
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (up(i, j))
        {
            g[i - 1][j] = 2;
           
            q.push(make_pair(i-1,j));
            d[i - 1][j] = d[i][j] + 1;
            re = max(re, d[i - 1][j]);
            k++;
        }
        if (down(i, j))
        {
            g[i + 1][j] = 2;
            q.push(make_pair(i+1,j));

            d[i + 1][j] = d[i][j] + 1;
            re = max(re, d[i + 1][j]);
            k++;
        }
        if (left(i, j))
        {
            g[i][j - 1] = 2;
            q.push(make_pair(i,j-1));
            d[i][j - 1] = d[i][j] + 1;
            re = max(re, d[i][j - 1]);
            k++;
        }
        if (right(i, j))
        {
            g[i][j + 1] = 2;
            q.push(make_pair(i,j+1));
            d[i][j + 1] = d[i][j] + 1;
            re = max(re, d[i][j + 1]);
            k++;
        }

        
    }


    if(cnt == k){
        cout << re;
    }
    else cout << -1;
}