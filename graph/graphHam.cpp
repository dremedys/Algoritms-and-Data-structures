#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
//given annagrams similar group
using namespace std;
class Solution {
private:    
    int hamdist(const  string &a, const  string &b)
    {  // compute hamming distance between two strings a and b
        int ans = 0;
        for (int i = 0, end = a.size(); i != end; ++i) {
            if (a[i] != b[i]) ++ans;
        }
        return (ans == 2);  // return true if they are similar, otherwise false
    }
    
    void BFS(int idx,  unordered_set<int> &seen, const  vector< vector<int>> &graph)
    {  
         deque<int> queue {idx};
        while (queue.size()) {
            const auto cur = queue[0];
            for (const auto &i : graph[cur]) {
                if (seen.find(i) == seen.end()) {
                    queue.push_back(i);
                    seen.insert(i);
                }
            }
            queue.pop_front();
        }
    }
public:
    int numSimilarGroups(vector<string>& A) {
	// preparation to reduce copies in A
	 unordered_set< string> tmp(A.cbegin(), A.cend());
	 vector< string> A_copy(tmp.cbegin(), tmp.cend());  // now that all strings in A_copy are distinct
	
	
        const auto l = A_copy.size();
         vector< vector<int>> graph(l,  vector<int>());  // this is the graph in adjacency list representation
        for (int i = 0; i != l ; ++i) {
            for (int j = i + 1; j != l; ++j) {
                if (hamdist(A_copy[i], A_copy[j])) {  // if they are similar
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }                
            }
        }
            
        int ans = 0;
         unordered_set<int> seen;
        for ( size_t i = 0; i != l; ++i) {
            if (seen.find(i) == seen.end()) {  // if we haven't visited it yet
                ++ans;  // we find a new group
                BFS(i, seen, graph);  // visit all nodes in this group
            }
        }
        
        return ans;
    }
};