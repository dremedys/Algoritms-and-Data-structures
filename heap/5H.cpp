#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
    public:
    vector<int> a;
    vector <int> sorted;

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }


    void insert(int x){
        a.push_back(x);
    }

    void heapify(int i) { 
        if (left(i) > a.size() - 1)
            return;
        
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] > a[left(i)])
            j = right(i);

        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    void buildHeap() 
    { 
    int nonLeaf = (a.size() / 2) - 1; 
    for (int i = nonLeaf; i >= 0; i--) { 
        heapify(i); 
    } 
    } 
    
    void extractMax() 
    { 
        int root = a[0]; 
        sorted.push_back(root);
        a[0] = a[a.size()-1]; 
        a.pop_back();
        heapify(0);
    } 

    void print() {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    void printSorted(){
        for(int i = sorted.size()-1;i>=0;--i){
            cout<< sorted[i]<<" ";
        }
        cout<<"\n";
    }
};
int main(){
	int n;
	cin>>n;
    MaxHeap *max_heap = new MaxHeap();
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x ;
        max_heap->insert(x);
    }
    max_heap->buildHeap();
    for(int i = 0; i < n ; i++){
        max_heap->print();
        max_heap->extractMax();
       
    }
    max_heap->printSorted();
	

}