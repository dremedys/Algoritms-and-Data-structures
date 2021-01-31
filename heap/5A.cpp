#include <iostream>
#include <vector>
//incr key
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

   void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
    }


    void increaseKey(int i, int new_value) {
        a[i] += new_value;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
		res.push_back(i);
    }

	void printRes(){
		for(int i=0;i<res.size();i++){
			cout<<res[i]+1<<"\n";
		}
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
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int x,add;
		cin>>x>>add;
		max_heap->increaseKey(x-1,add);
	}
	max_heap->printRes();
	
	max_heap->print();

}