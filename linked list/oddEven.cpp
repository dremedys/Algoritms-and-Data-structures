
 //given a linked list you need to return list that shows first odd nodes then even nodes
 //example Input: 2->1->3->5->6->4->7->NULL
//Output: 2->3->6->7->1->5->4->NULL
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      if(head==nullptr) 
        return nullptr;
    //the idea is to keep odd and even nodes in dif linked list and in the end just next of last odd make head of even
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even!=nullptr && even->next!=nullptr){ //while there are nodes
          odd-> next = even->next;  //odd's next is even's next logically
          odd = odd->next;  //do it for next odd but it is even node
          even->next= odd->next; //so this even node is even's next
          even = even->next;  //do it for next this is odd sooo
        }
      odd->next = evenHead; //so understood yeah
      return head;
    }
};