
#include <iostream>  //we include iostream to use cin and cout
#include <vector>
using namespace std;  //i dont know

class Node { 
    public:
    char value; 
    Node *ch[26]; 
    vector<int> idx;

    Node(char value) { 
        this->value = value;
        for (int i = 0; i < 26; i++)
            this->ch[i] = NULL;  
    }

};


class Trie {
    public:
    Node *root;
    Trie() {
        root = new Node(' ');  //root node will be anything except english letters
    }

    void insert(string s,size_t k) {
        Node *cur = root;    
        for (size_t i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL) 
                cur = cur->ch[s[i] - 'a'];
            else {
                Node *node = new Node(s[i]); 
                cur->ch[s[i] - 'a'] = node;  
                cur = node;  
               
            }
            cur->idx.push_back(k);
        }
    }
    void search(string p){
        Node *cur = root;
        vector<int> nope;
        for(size_t i = 0 ; i < p.size(); i++){
            if(cur->ch[p[i] - 'a'] == NULL){
                cout << 0 << endl;
                return;
            }
            cur = cur->ch[p[i] - 'a'];
        }
        cout << cur->idx.size()<<" "; 
        for(size_t i = 0  ; i < cur->idx.size();i++){
            cout << cur->idx[i] + 1<<" ";
        }
        cout << endl;
    }
};

int main() {
    Trie *trie = new Trie();
    vector<string> words;
    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++) {
        string s1 = s.substr(i);  
        trie->insert(s1,i);
    }
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        words.push_back(s);
    }
    for(size_t i = 0 ; i < words.size();i++){
        trie->search(words[i]);
       
    }
    cout<<endl;
    return 0;
}