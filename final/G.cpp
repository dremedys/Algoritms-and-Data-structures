
#include <iostream>  
#include <vector>
using namespace std; 

class Node { 
    public:
    char value;
    Node *ch[26]; 
    int cnt;
    bool isEnd;
    Node(char value) {  
        this->value = value;
        for (int i = 0; i < 26; i++)
            this->ch[i] = NULL;  
        this->cnt = 0;
        this->isEnd=false;
    }
};

class Trie {
    public:
    Node *root;
    Trie() {
        root = new Node(' '); 
    }

    void insert(string s) {
        if(!exists(s)){
            Node *cur = root;   
        for (int i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL) 
                cur = cur->ch[s[i] - 'a'];
            else {
                Node *node = new Node(s[i]); 
                cur->ch[s[i] - 'a'] = node;   //declare node as new place of cureent
                cur = node;  //start working with new place
                  //new vertice was added
            }
            cur->cnt++;
        }
        cur->isEnd=true;
        }
        
        
    }
    bool exists(string s){ 
        Node* cur = root;
        for (int i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL)
                cur = cur->ch[s[i] - 'a'];
            else  
                return false;
        }
        return cur->isEnd;
    }
    void udalit(string s){
        Node* cur = root;
        if(!exists(s)) 
            return;
        for (int i = 0; i < s.size(); i++) {
            cur = cur->ch[s[i] - 'a'];
            cur->cnt--;
        }
        cur->isEnd=false;
        
    }
    int count(string s){
        Node* cur = root;
        for (int i = 0; i < s.size(); i++) {
            if(cur->ch[s[i]-'a'] != NULL){
                cur = cur->ch[s[i] - 'a'];
            }
            else
                return 0;
        }
         return cur->cnt;

    }
};

int main() {
    Trie *trie = new Trie();
    int n;
    string s;
    cin >> n;
    int j = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        char x; cin >> x;
        if(x == '+') {
            j ++;
            cin >> s;
            trie->insert(s);

        } else if(x == '-') {
            cin >> s;
            trie->udalit(s);
        } else if (x == '?'){
            cin >> s;
           
            ans.push_back(trie->count(s));
        }
    }
    for(int i = 0 ; i < ans.size();i++){
        cout << ans[i]<<"\n";
    }
}