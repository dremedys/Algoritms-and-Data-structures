# include <iostream>
using namespace std;
int main() {
  int n, m;
  cin>>n>>m;
  int a[n][m], minRows[n], maxCols[m];
 
  for (int i = 0; i <n; i++) {
    for (int j = 0; j < m; j++) {
      cin>>a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    minRows[i] = a[i][0];
    for (int j = 0; j < m; ++j) {
      if(a[i][j]<minRows[i]){
          minRows[i]=a[i][j];
      }
    }
  }

  for (int j = 0; j < m; ++j) {
    maxCols[j] = a[0][j];
    for(int i=0;i<n;i++){
    if (a[i][j]>maxCols[j]){
        maxCols[j]=a[i][j];
    }
    }
  }

  int cnt = 0;
  for (int i = 0; i <n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (minRows[i] == a[i][j] && maxCols[j] == a[i][j]) {
        cnt++;
      }
    }
  }
  cout <<cnt;
  return 0;
}
