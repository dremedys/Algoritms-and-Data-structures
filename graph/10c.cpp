#include <iostream>
#include <stack>
using namespace std;
stack<int> st;
int n, s;
int g[100][100];
int main()
{

    cin >> n >> s;
    s--;

    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    }

    for (int j = 0; j < n; j++)
    {
        if (g[s][j] == 1)
            st.push(j);
    }

    g[s][s] = 1;

    while (st.empty() == false)
    {
        int cur = st.top();
        st.pop();
        if (g[cur][cur] == 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[cur][j] == 1)
                    st.push(j);
            }
            cnt++;

            g[cur][cur] = 1;
        }
    }

    cout << cnt;
    return 0;
}