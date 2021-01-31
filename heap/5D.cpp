#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
    public:
    vector<int> a;

    unsigned int parent( int i) {
        return (i - 1) / 2;
    }
    unsigned int left(unsigned int i) {
        return 2 * i + 1;
    }
    unsigned int right(unsigned int i) {
        return 2 * i + 2;
    }
    void insert(unsigned int k,unsigned int n) {
        if(a.size() >= n  ){
            cout<<-1<<"\n";
        }
        else{
            a.push_back(k);
            unsigned int i = a.size() - 1;
            while (i > 0 && a[parent(i)] < a[i]) {
                        swap(a[parent(i)], a[i]);
                        i = parent(i);
            }
            cout<<i+1<<"\n";
        }
    }
    
    unsigned int heapify(unsigned int i) {

        while(left(i)<a.size()){

            if(right(i)<a.size() && a[right(i)]> a[left(i)]){
                if(a[right(i)] > a[i]){
                    swap(a[i],a[right(i)]);
                    i= right(i);           
                }
                else if(a[left(i)] > a[i]){
                    swap(a[i],a[left(i)]);
                    i= left(i);   
                }
                else{
                    break;
                }
                
            }
            else if((right(i)>=a.size() || a[right(i)]<= a[left(i)]  ) && a[left(i)] > a[i]){
                    swap(a[i],a[left(i)]);
                    i= left(i); 
            }
            else{
                break;
            }
        }
        return i; 
    }
    void extractMax() 
    { 
        if(a.size() == 0){
            cout<<-1<<"\n";
        }
        else if(a.size() == 1){
            int root = a[0];
            a.pop_back();
            cout<< 0 << " " << root<<"\n";
        }
        else{
            int root = a[0]; 
            swap(a[0],a[a.size()-1]);
            a.pop_back();
            cout<< heapify(0)+1<<" "<< root<<"\n";  
        }
         
    } 
    
    void print() {
        for (unsigned int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
    }
};
int main(){
	unsigned int n;
    unsigned int k;
	cin>>n>>k;
    MaxHeap *max_heap = new MaxHeap();
    for(unsigned int i = 0 ; i < k ; ++i){
        unsigned int j;
        cin >> j;
        if(j ==1 ){
            max_heap->extractMax();
        }
        else if(j == 2){
            int add;
            cin>>add;
            max_heap-> insert(add,n);
        }
    }
    max_heap->print();
	

}