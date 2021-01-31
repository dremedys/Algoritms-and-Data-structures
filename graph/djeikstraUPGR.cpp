#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INF = 1000000000;

int main() {
	int n;
	cin >> n;
	vector < vector < pair<int,int> > > g (n);
	//... чтение графа ...
	int s = 0; // стартовая вершина
 
	vector<int> d (n, INF),  p (n);
	d[s] = 0;
	set < pair<int,int> > q;
	q.insert (make_pair (d[s], s)); //first insert that first guy
	while (!q.empty()) { //while set has element
		int v = q.begin()->second; //take that vertex in set
		q.erase (q.begin()); //delete him
 
		for (size_t j=0; j<g[v].size(); ++j) {  //work with his neighbors
			int to = g[v][j].first, //take a neighbor
				len = g[v][j].second; //take a distance
			if (d[v] + len < d[to]) { //if new dis is better 
				q.erase (make_pair (d[to], to)); //deletee last
				d[to] = d[v] + len;
				p[to] = v;
				q.insert (make_pair (d[to], to));//add better one
			}
		}
	}
}