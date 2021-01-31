#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int x, y;
int n;
queue<int> q;
bool used[100];
int g[100][100];
vector<int> d(100), p(100);

void bfs(int v) //for adj matrix
{
    p[x] = -1;
    q.push(v); //add given vertix

    used[v] = true; //assign it as used

    while (!q.empty())
    {
        int top = q.front(); //take last vertex as top
        q.pop();             //delete from queue

        for (int i = 0; i < n; ++i) //start finding his neighbors
        {
            int cur = g[top][i];        //cur is 0 or 1
            if (cur != 0 && (!used[i])) //if is not zero then is neighber check if used
            {
                used[i] = true; //make used
                q.push(i);      //this neighbor must be obxodit

                d[i] = d[top] + 1; //to rich i from start you must do d[i] steps
                p[i] = top;        //parent of i is top
            }
        }
    }
}
int main()
{
    cin >> n;                   //number of vertices
    for (int i = 0; i < n; i++) //read adj matrix
    {
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    }

    cin >> x >> y; //from where to where

    x--;
    y--;

    //x will not have parent for us

    bfs(x);       //obxod it then
    if (!used[y]) //if when obxoding y was not even rached NO cause they arent in same componenta even
        cout << -1;

    else
    { //then have path

        cout << d[y] << "\n";
        if (d[y] != 0)
        {
            vector<int> path;
            for (int v = y; v != -1; v = p[v]) //start from y find parents while get parenty(x) and reverse it
                path.push_back(v);
            reverse(path.begin(), path.end());

            for (size_t i = 0; i < path.size(); ++i)
                cout << path[i] + 1 << " ";
        }
    }
}
