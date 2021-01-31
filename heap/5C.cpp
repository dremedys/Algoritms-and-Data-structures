#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
    public:
    vector<int> a;
	vector<int> res;


    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    int heapify(int i) {
       while(left(i)<a.size() && (a[i]<a[left(i)] || a[i]<a[right(i)])){
           if(a[left(i)]>a[right(i)]){
               swap(a[left(i)],a[i]);
               i = left(i);
           }
           else{
               swap(a[right(i)],a[i]);
               i = right(i);
           }
       } 
       return i;
    }
  
           


    void extractMax() 
    { 
        int root = a[0]; 
        a[0] = a[a.size()-1]; 
        a.pop_back();
        cout<< heapify(0)+1<<" "<< root<<"\n"; 
        
    } 
};
int main(){
	MaxHeap *max_heap = new MaxHeap();
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int z;
		cin>>z;
		max_heap->insert(z);
	}
	for(int i = 0; i< n-1 ; ++i){
        max_heap->extractMax();
    }

}