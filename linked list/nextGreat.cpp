#include <iostream>
#include <vector>
#include <stack>
//find value of next greater element
using namespace std;

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int pos=-1;
        stack<pair<int,int>> s;
        ListNode* itr=head;
        int n=0;
        while (itr!=NULL){
            itr=itr->next;
            n+=1;
        }
        vector<int> v(n,0);
        while(head!=NULL){
            pos+=1;
            if (!s.empty()){
                if (((s.top()).first)<head->val){
                    while (!s.empty() && (s.top()).first<head->val){
                        v[(s.top()).second]=head->val;
                        s.pop();
                    }
                }
            }
            s.push(make_pair(head->val,pos)); 
            head=head->next;
        }
        return v;
    }
};