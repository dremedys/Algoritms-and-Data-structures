#include <iostream>
#include <vector>
using namespace std; //show all path from 0 to n-1
class Solution {
public:
    int target; //index of needed place
    vector<int> tmp;  //save temp result
    vector< vector<int> > ans; //answer vector
    void dfs(vector<vector<int>>& graph,int cur){ //it starts from zero
      tmp.push_back(cur);  //adding okay
      if(cur == target){  //if it is already what we want add that answer
        ans.push_back(tmp);
      }
      else{
        for(int i = 0 ; i < graph[cur].size();i++){ //else look at his neighbors
          int now = graph[cur][i]; //take every neighbor
          dfs(graph,now);  //start finding answer
        }
      }
      tmp.pop_back();
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size() - 1;
        dfs(graph,0);
        return ans;
    }
};