#include <iostream>
#include <vector>
using namespace std;
//given a sorted array that was rotated n time, find smallest element.                                                  
//it is binary search problem which needs to be modified
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1 ){ //if array contains only one element return it.
          return nums[0];
        }
      
      int left = 0 , right = nums.size() - 1;

      if(nums[right] > nums[0]){ //if it is not rotated then return first number
        return nums[0];
      }
      
      while(left <= right){
        int mid = left + (right-left)/2;
        if(nums[mid] > nums[mid+1]){  //if we find element that is less then before element it is that minimum
          return nums[mid+1];
        }
        if(nums[mid] < nums[mid - 1]){ //or mid is smallest
          return nums[mid];
        }
        if(nums[mid] > nums[0]){ //if random is bigger than first element move left one more step
          left = mid + 1;
        }
        else right = mid -1; //else right must go back.
      }
      return -1;
    }
};
int main(){
    cout << (5+10 >> 2);
}