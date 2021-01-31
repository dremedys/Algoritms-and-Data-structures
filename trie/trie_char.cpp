
#include <iostream>  

using namespace std; 

class Node { 
    public:
    char value; //value of char
    Node *ch[26]; 

    Node(char value) {  //simple costructor
        this->value = value;
        for (int i = 0; i < 26; i++)
            this->ch[i] = NULL;  
    }
};

int cnt = 0; 

class Trie {
    public:
    Node *root;
    Trie() {
        root = new Node(' '); 
    }

    void insert(string s) {
        Node *cur = root;   
        for (int i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL)  //if there adlready exists such letter start working with it
                cur = cur->ch[s[i] - 'a'];
            else {
                Node *node = new Node(s[i]); //else create a new place
                cur->ch[s[i] - 'a'] = node;   //declare node as new place of cureent
                cur = node;  //start working with new place
                cnt++;  //new vertice was added
            }
        }
    }
};

int main() {
    Trie *trie = new Trie();
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        string s1 = s.substr(i);  //substring which starts from i=0 must be added
        trie->insert(s1);
    }
    cout << cnt; //number of vertices of trie = number of different substrings in the string
    return 0;
}