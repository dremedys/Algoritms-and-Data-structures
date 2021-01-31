#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

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

    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
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
    max_heap->print();
	

}