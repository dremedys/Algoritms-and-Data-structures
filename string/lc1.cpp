#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Given a string s, you can convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
class Solution {
public:

vector<int> prefix_function (string s) { //so let's try to write a pi function
	int n = (int) s.length();  //to antiwaste writng length let's call it n
	vector<int> pi (n);  //we make vector of n to keep pref func of every prefix
	for (int i=1; i<n; ++i) {  // s[0] is 0 , so let's start from 1
		int j = pi[i-1];  //to compare we dont take already was functions just,cause there is sit when s[i]!=s[pi[i]]+1
		while (j > 0 && s[i] != s[j]) //we tryna find not max prefix,but only j should not be that bad like 0
			j = pi[j-1]; //but if was equal this wont even start working
		if (s[i] == s[j])  ++j; //so if we found it just +1,no?
		pi[i] = j; //alright we found it
	} //notice if prev pi was 0 it will stay like 0)) omg I am so genious
	return pi;
}
string shortestPalindrome(string s)
{
    string rev(s);
    int n = s.size();
    reverse(rev.begin(), rev.end());
    string z = s+"#"+rev;
    int n_new=z.size();
  vector<int> f = prefix_function(z);
    return rev.substr(0, n - f[n_new - 1]) + s;
}
};