#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int leftBow(vector<int>&a,int x){
  //index of minimum number that is greater than x or equal to x
  int left=-1,right=a.size();
  while(left+1<right){
    int mid = (left+right)/2;
    if(a[mid] >= x){
      right = mid;
    }
    else
    {
      left= mid;
    }
  }
  return right;
}
int rightBow(vector<int>&a,int x){
  //index of maximum number that is less than x or equal to x
  int left=-1,right=a.size();
  while(left+1<right){
    int mid = (left+right)/2;
    if(a[mid] <= x){
      left = mid;
    }
    else
    {
      right= mid;
    }
  }
  return left;
}
int reply(vector<int>&a , int l, int r){
  
      return rightBow(a,r) - leftBow(a,l) + 1;
    
}
int main(){
  int n;
  cin >> n;
  vector<int> a;
  for(int i = 0 ; i < n ;i++){
    int x;
    cin>>x;
    a.push_back(x);
  }
  sort(a.begin(),a.end());
  int t;
  cin >>t;
  vector<int> ans;
  for(int i = 0 ; i < t;i++){
    int x,y;
    cin >> x >>y;
    ans.push_back(reply(a,x,y));
   //cout << leftBow(a,x) << " " << rightBow(a,y)<<"\n";
  }
  for(int i = 0 ; i < ans.size();i++){
    cout << ans[i] <<" ";
  }
  //1 3 4 10 10
}