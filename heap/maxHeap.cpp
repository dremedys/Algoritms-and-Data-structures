#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//this is maxheap that keeps frequency of elements in array. 
class MaxHeap {
    public:
    vector<pair<int,int>> a;
   int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int x,int y){
        a.push_back(make_pair(x,y));
      int i = a.size() - 1;
        while (i > 0 && a[parent(i)].first < a[i].first) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void heapify(int i) { 
        if (left(i) > a.size() - 1)
            return;
        
        int j = left(i);
        if (right(i) < a.size() && a[right(i)].first > a[left(i)].first)
            j = right(i);

        if (a[i].first < a[j].first) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    void extractMax() 
    { 
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);

    } 
    
    

};
class Solution {
public:
  vector<int> ans;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size()) {
          return nums;
        }
      unordered_map<int,int> cnt;
      for(int i= 0 ; i < nums.size() ; i++){
        cnt[nums[i]]++;
      }
      MaxHeap* maxHeap  = new MaxHeap();
      for(auto i : cnt){
        maxHeap->insert(i.second,i.first);
      }

      for(int i = 0 ; i< k ; i++){
       // ans.push_back(maxHeap->extractMax());
        
      }
      return ans;
    }
};