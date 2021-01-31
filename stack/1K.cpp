#include <iostream>
using namespace std;
bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i*i<=num; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}
int main(){
   int num;
   bool flag;
   cin>>num;
   
   flag = isPrime(num);
   if (flag)
      cout<<"prime";
   else
      cout<<"composite";
   return 0;
}