
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
};
