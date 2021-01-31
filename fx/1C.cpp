#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, m;

vector<int> g[100];

set<int> nezat;
int main()
{
    cin >> n >> m;
    m--;
    while (true)
    {
        int x;
        cin >> x;
        if (x)
        {
            int y;
            cin >> y;
            x--;
            y--;
            g[x].push_back(y);
        }
        else
            break;
    }
  
   bool ok = true;
   
    for(int i = 0 ; i < n ; i++){
        if(!g[i].empty()) nezat.insert(i);
        for(int j = 0 ; j < g[i].size();j++){
            nezat.insert(g[i][j]);
            if(g[i][j] == m){
                    ok = false;
                    break;
            }
                
        }
    }
    if(ok && nezat.size()==n) cout<<"Yes";
    else cout << "No";
}