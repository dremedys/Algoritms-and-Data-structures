#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min && a[i] != max)
            min = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == max)
            a[i] = min;
        cout << a[i] << " ";
    }
}