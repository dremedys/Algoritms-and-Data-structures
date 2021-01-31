#include <iostream>
#include <vector>
using namespace std;
vector<int> prefix_function (string s) { 
	int n = (int) s.length(); 
	vector<int> pi (n); 
	for (int i=1; i<n; ++i) {  
		int j = pi[i-1]; 
		while (j > 0 && s[i] != s[j]) 
			j = pi[j-1];
		if (s[i] == s[j])  ++j; 
		pi[i] = j; 
	} 
	return pi;
}


int main(){
    string s;
    long long  cnt = 0;
    cin>>s;

    vector<int> p = prefix_function(s);

    for(int i = 0 ; i < p.size();i++){
        if(i+i < p.size()-1 && i+p[i] == p[i+i] && p[i] != 0 ){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}