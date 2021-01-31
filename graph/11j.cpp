#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isRed[100]; //i-th vertex is isRed

vector<int> g[100];

int closest(int top, int n) 
{ //top is searching vertex, n is number of vertex
    if (isRed[top]) //if given vertex is already isRed 
        return 0; //distance from self to self

    queue<int> q;

    vector<bool> used(n, 0); 
    int d[n];                //vector of distances
    q.push(top);
    d[top] = 0;
    used[top] = true;
   
    while (!q.empty())
    {
        int top = q.front();
        for (int i = 0; i < g[top].size(); i++)
        {
            int cur = g[top][i];
            if (!used[cur])  //if not visited vertex
            {
                if (isRed[cur]) 
                {
                    d[cur] = d[top] + 1; 
                    return d[cur]; //RETURN FIRST isRed OCCURENCE
                }
                else
                {  
                    d[cur] = d[top] + 1;
                    used[cur] = true;
                    q.push(cur);
                }
            }
        }
        q.pop();
    }

    return -1;
}
int main()
{
    int x, y, n, m, queryNum, type, r;
    cin >> n >> m >> queryNum;
    vector<int> ans; //answers to require of type 2
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for (int i = 0; i < queryNum; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> r;
            r--;
            isRed[r] = true;
        }
        else
        {
            cin >> r;
            r--;
            ans.push_back(closest(r, n));
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    // Orazbek.productivity[december2] = true;
}