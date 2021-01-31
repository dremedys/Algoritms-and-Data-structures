#include <bits/stdc++.h>
using namespace std;
queue<string> q;
map<string, int> dis;
string s1, s2;
map<string, string> parent;
bool ok(string s)
{
    return dis[s] == 0 && s != "";
}
string inc(string s)
{
    if (s[0] != '9')
    {
        s[0] += 1;
        return s;
    }
    else
        return "";
}
string dec(string s)
{
    if (s[3] != '1' && s[3] != 0)
    {
        s[3]--;
        return s;
    }
    else if (s[3] == 0)
    {
        s[3] = '9';
        return s;
    }
    return "";
}
string left(string s)
{
    string k = "";
    k += s[1];
    k += s[2];
    k += s[3];
    k += s[0];
    return k;
}
string right(string s)
{

    string k = "";
    k += s[3];
    k += s[0];
    k += s[1];
    k += s[2];
    return k;
}
int main()
{
    cin >> s1 >> s2;
    dis[s1] = 1;
    parent[s1] = "stop";
    q.push(s1);
    while (!(q.empty()))
    {
        string top = q.front();
        if (ok(dec(top)))
        {
            q.push(dec(top));
            dis[dec(top)] = dis[top] + 1;
            parent[dec(top)] = top;
        }
        if (ok(inc(top)))
        {
            q.push(inc(top));
            dis[inc(top)] = dis[top] + 1;
            parent[inc(top)] = top;
        }
        if (ok(left(top)))
        {
            q.push(left(top));
            dis[left(top)] = dis[top] + 1;
            parent[left(top)] = top;
        }
        if (ok(right(top)))
        {
            q.push(right(top));
            dis[right(top)] = dis[top] + 1;
            parent[right(top)] = top;
        }
        q.pop();
    }
    vector<string> ans;
    for (string vertice = s2; vertice != "stop"; vertice = parent[vertice])
    {
        ans.push_back(vertice);
    }
    
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << "\n";
    }
}
