#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool exists(int num, vector<int> &a)
{
    int left = 0;
    int right = a.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == num)
        {
            return true;
        }
        else if (a[mid] < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
class Node
{
public:
    char value;
    Node *ch[26];
    bool isEnd;
    Node(char value)
    {
        this->value = value;
        this->isEnd = false;
        for (int i = 0; i < 26; i++)
            this->ch[i] = NULL;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node(' ');
    }

    void insert(string s)
    {
        Node *cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (cur->ch[s[i] - 'a'] != NULL)
                cur = cur->ch[s[i] - 'a'];
            else
            {
                Node *node = new Node(s[i]);
                cur->ch[s[i] - 'a'] = node;
                cur = node;
            }
        }
        cur->isEnd = true;
    }
    vector<int> search(string s)
    {
        Node *cur = root;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (cur->ch[s[i] - 'a'] != NULL)
            {

                cur = cur->ch[s[i] - 'a'];
                if (cur->isEnd)
                {
                    ans.push_back(i + 1);
                }
            }

            else
                break;
        }
        return ans;
    }
};

int main()
{
    Trie *trie = new Trie();
    Trie *trieRev = new Trie();

    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string ne;
        cin >> ne;
        trie->insert(ne);
        reverse(ne.begin(), ne.end());
        trieRev->insert(ne);
    }

    vector<int> pref = trie->search(s);
    reverse(s.begin(), s.end());
    vector<int> suff = trieRev->search(s);
   
    int k = s.size();

    bool ok = false;
    
    for (int i = 0; i < pref.size(); i++)
    {
        if (exists(k - pref[i], suff))
        {
            ok = true;
            break;
        }
    }
    if (ok)
        cout << "YES";
    else
        cout << "NO";

}