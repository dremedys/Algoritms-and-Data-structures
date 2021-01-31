#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> adj;  //keep neighbour of every vertex
vector<char> color;  // initilaly all are white(0)  , might become gray(1) or black(2)
vector<int> parent;  //to keep parent of every vertex
int cycle_start, cycle_end;  //to detect cycle

bool dfs(int v) {
    color[v] = 1;  //antiused one will become grey first
    for (int u : adj[v]) { //traverse all his neighbours
        if (color[u] == 0) {  //if still not used assign his parent
            parent[u] = v;
            if (dfs(u))  
                return true;
        } else if (color[u] == 1) {   //if we found gray WE FOUND CYCLE
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;  //in the end make him black
    return false;
}

void find_cycle() {
    color.assign(n, 0); //make all white again
    parent.assign(n, -1); //make all zhetim again
    cycle_start = -1; //think we dont have cycle

    for (int v = 0; v < n; v++) {   
        if (color[v] == 0 && dfs(v))
            break;  //dfs all
    }

    if (cycle_start == -1) {   //if if didnt change there is no cycle
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;  //looking for cycle
        cycle.push_back(cycle_start); 
        for (int v = cycle_end; v != cycle_start; v = parent[v]) //go to find his parents while we get a zhetim one i mean most argy ata
            cycle.push_back(v);
        cycle.push_back(cycle_start);  //of course cycle end is cycle start
        reverse(cycle.begin(), cycle.end()); 

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}