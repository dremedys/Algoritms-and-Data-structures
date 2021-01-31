#include <bits/stdc++.h>
using namespace std;
int g[100][100];
int sum, a, b, c;
int main()
{
    int mini = 3001;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                for (int k = 0; k < n; k++)
                    if (k != j && k != i && (sum = g[i][j] + g[j][k] + g[k][i]) < mini)
                    {
                        mini = sum;
                        c = i;
                        a = j;
                        b = k;
                    }
        }
    }

    cout << min(a, min(b, c)) + 1 << " " << a + b + c - max(max(a, b), c) - min(a, min(b, c)) + 1 << " " << max(max(a, b), c) + 1;
}
