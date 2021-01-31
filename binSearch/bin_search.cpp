#include <iostream>

using namespace std;

int left_bound(int A[], int N, int x)
{
    int left = -1;  
    int right = N;  
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (A[middle] < x)
            left = middle;
        else
            right = middle;
    }    
    return left;
}

int find(int A[], int N, int x)
{
    int left = left_bound(A, N, x);
    int potential_first_index_of_x_in_A = left + 1;
    if (potential_first_index_of_x_in_A < N and 
        A[potential_first_index_of_x_in_A] == x)
        return potential_first_index_of_x_in_A;
    else
        return -1; // x not found

}

int main()
{
    int N ;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++) cin>>A[i];
    int x;
    cin >> x;
    cout << "left boundary of x is: " << left_bound(A, N, x) << '\n';

    return 0;
}
