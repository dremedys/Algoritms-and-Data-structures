#include <queue>
#include <vector>
#include <iostream>
using namespace std;


int ans(vector<int> &stones)
{
    priority_queue<int> pq;

    for (int i = 0; i < stones.size(); i++)
    
        pq.push(stones[i]);
    
    while (pq.size() >= 2)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        if (first != second)
            pq.push(first - second);
        if (pq.empty())
            return 0;
    }
    return pq.top();
}
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << ans(a);
}