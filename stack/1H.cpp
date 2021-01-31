#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int k;
	cin>>k;
	deque<int> d;
    deque<int> res;
	for(int i = 0;i<k;i++){
		char s;
		cin>>s;
		if(s=='+'){
			int n;
			cin>>n;
			d.push_back(n);
		}
		else if(s=='*'){
			int n;
			cin>>n;
			d.push_front(n);
		}
		else{
			cout<<res.front()<<endl;
			res.pop_front();
		}
		if(res.size()<d.size()){
			res.push_back(d.front());
			d.pop_front();
		}

	}	
}