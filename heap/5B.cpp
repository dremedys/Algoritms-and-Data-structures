#include <iostream>
#include <vector>

using namespace std;
vector<int> a;
vector<int> res;
int parent(int i) {
    return (i - 1) / 2;
}

unsigned int left(int i) {
    return 2 * i + 1;
}

unsigned int right(int i) {
    return 2 * i + 2;
}



void print() {
    for (unsigned int i = 0; i < a.size(); i++) 
        cout << a[i] << " ";
    cout << endl;
}


int heapify(int i) {

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
        else if((right(i)>=a.size() || a[right(i)]< a[left(i)]  ) && a[left(i)] > a[i]){
                swap(a[i],a[left(i)]);
                i= left(i); 
        }
        else{
            break;
        }
    }
    return i; 
}
void decreaseKey(unsigned int i, int new_value) {

    a[i] -= new_value;
    res.push_back(heapify(i));
}

void printRes(){
    for(unsigned int i=0;i<res.size();i++)
        cout<<res[i]+1<<"\n";
    
}


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int z;
		cin>>z;
		a.push_back(z);
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		unsigned int x;
        int add;
		cin >> x >> add;
		decreaseKey(x-1, add );
	}
	printRes();
	print();

}