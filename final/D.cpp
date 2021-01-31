#include <iostream>
#include <vector> 
using namespace std;
vector<int> prefix_function (string s) { 
	int n = (int) s.length();
	vector<int> pi (n); 
	for (int i=1; i<n; ++i) { 
		int j = pi[i-1]; 
		while (j > 0 && s[i] != s[j]) 
			j = pi[j-1]; //but if was equal this wont even start working
		if (s[i] == s[j])  ++j;
		pi[i] = j; 
	} 
	return pi;
}
int ans(string s,string t){
	string p = t + "#" + s + s;
	int size = t.size();
	int new_size = p.size();
	vector<int> pi = prefix_function(p);
	for(int i = new_size ; i >=0;i--){
		if(pi[i] == size && t == p.substr(i-size+1,size)){
			return new_size-i-1;
		}
	}
	return -1;
}
int main(){
    int n;
    cin>>n;
	string s;
	string t;
	cin>>s>>t;
	cout<<ans(s,t);
	return 0;

}