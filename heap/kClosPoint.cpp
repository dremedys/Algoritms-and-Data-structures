#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//given points,return k points that are closest to origin
class MinHeap {
    public:
    vector< pair<double, pair<int,int>> > a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(double dis , int x,int y) {
        a.push_back(make_pair(dis,make_pair(x,y)));
        int i = a.size() - 1;
        while (i > 0 && a[parent(i)].first > a[i].first) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        
        int j = left(i);
        if (right(i) < a.size() && a[right(i)].first< a[left(i)].first)
            j = right(i);

        if (a[i].first > a[j].first) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

      void extractMin() {
        pair<int,int> root = a[0].second;
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        //return root;
    }
  bool empty(){
    return a.empty();
    
  }
  int one(){
      return a[0].second.first;
    }
    int two(){
      return a[0].second.second;
    }
};
class Solution {
    public:
    double dis(int x,int y) {
      return sqrt(x*x + y*y);}
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        MinHeap* mh = new MinHeap();
        for(int i = 0 ; i < points.size();i++){
          int x = points[i][0]; int y = points[i][1];
          mh->insert(dis(x,y),x,y);
        }
      int cnt = 1;
      vector<vector<int> > res;
      while(!(mh->empty()) && cnt <= K){
        vector<int> para;
        
        para.push_back(mh->one());
        para.push_back(mh->two());
        res.push_back(para);
        mh->extractMin();
        cnt++;
      }
    return res;
            }    
};