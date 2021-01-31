#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node *ch[2];
    int cnt;

    Node(int value) {
        this->value = value;
        this->ch[0] = NULL;
        this->ch[1] = NULL;
        this->cnt = 0;
    }
};

int a[100][100];
int n;

class Trie {
    public:
    Node *root;
    Trie() {
        root = new Node(' ');
    }
    void insert(int row) {
        Node *cur = root;
        for (int i = 0; i < n; i++) {
            int k = a[row][i];
            if (cur->ch[k] != NULL) {
                cur = cur->ch[k];
            }
            else {
                Node *node = new Node(k);
                cur->ch[k] = node;
                cur = node;
            }
            if (i == n - 1)
                cur->cnt++;
        }
    }
    int b[100];
    void search(Node *node, int d) {
        if (d > 0) {
            b[d - 1] = node->value;
        }
        if (d == n) {
            for (int i = 0; i < n; i++)
                cout << b[i];
            cout << " - " << node->cnt;
            cout << endl;
        } else {
            for (int i = 0; i <= 1; i++) {
                if (node->ch[i] != NULL)
                    search(node->ch[i], d + 1);
            }
        }
    } 
};

int main() {
    Trie *trie = new Trie();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
        trie->insert(i);
    }
    trie->search(trie->root, 0);
    return 0;
}