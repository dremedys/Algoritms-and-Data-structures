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

    void insert(int k) {
        
            a.push_back(k);
            int i = a.size() - 1;
            while (i > 0 && a[parent(i)] < a[i]) {
                    if(a[parent(i)]!= a[i]){
                        swap(a[parent(i)], a[i]);
                        i = parent(i);
                    }
                    else i=parent(i);
                    
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
    max_heap->print();
	
}