#include <iostream>
#include <vector>
int q = 101;
using namespace std;
int hashCode(string s) {
    int ans = 0;
    int power = 1;
    for (int i = 0; i < s.size(); i++) {
        ans += ((s[i] - 'a' + 1)*power) % q;
        power = (power*31)%q;
    }
    return ans;
}

vector<int> easyHash(string s,int n) {
    vector<int> hashCode(n);
    int power = 1;

    hashCode[0] = (s[0] - 'a' + 1)%q;   // h[2] = s[0]*p^0 + s[1]*p^1 + s[2] * p^2
    for (int i = 1; i < n; i++) {   // h[3] = s[0]*p^0 + s[1]*p^1 + s[2] * p^2 + s[3] * p^3.. I mean new one is adding
        power = (power*31)%q;         //just adding this char multiplied by that power of p
        hashCode[i] = (hashCode[i - 1] + (s[i] - 'a' + 1)* power)%q;
    }
    return hashCode;
} 

int main() {
    string s;
    string t;
    cin >> s >> t;

    int h = hashCode(t);
    int n = s.size();  //we use size() instead of length() causeit is comfortable for stl structure (here vectors)
    int m = t.size();

    vector<int> hash = easyHash(s,n); //HERE!!))) we will store here hashcodes of the text

    int powers[n];  //just store here pow(p,i)
    powers[0] = 1;
    for (int i = 1; i < n; i++)
        powers[i] = (powers[i - 1] * 31)%q; //very useful right?.. time is very important for us

    for (int i = 0; i < n - m + 1; i++) { 
        int j = i + m - 1; 
        int hash2 = hash[j];

        if (i > 0) 
             hash2 -= hash[i - 1];

        if (hash2 == h * powers[i]) { 
            cout << i << " ";
        }
    }
}
