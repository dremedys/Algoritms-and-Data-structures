
#include <iostream>
using namespace std;
//CHECK IF GIVEN linked list is palindrome
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    //ListNode(int x, ListNode  next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head; 
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) //finding mid element (slow)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *prev = NULL;
        while (slow != NULL) //reversing  next half
        {
            ListNode *tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        ListNode *left = head;
        ListNode *right = prev;
        while (right != NULL)
        {
            if (left->val != right->val)
            {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};