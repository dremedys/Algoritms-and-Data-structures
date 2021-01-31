#include <iostream>
using namespace std;
bool isGood(long long first,long long sec,long long third,long long time,long long tasks){
    return (time/first+time/sec+time/third>=tasks);
}
int main(){
    long long tasks;
    long long first,sec,third;
    cin>>tasks>>first>>sec>>third;
    long long left=0;
    long long right=100000000;
    while(right>left+1){
        long long mid=(left+right)/2;
        if(isGood(first,sec,third,mid,tasks)){
            right=mid;
        }
        else{
            left=mid;
        }
    }
    cout<<right;
}