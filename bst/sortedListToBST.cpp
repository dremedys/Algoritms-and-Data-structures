/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> a;
    void makeArray(ListNode* head){
        while(head!=NULL){
            a.push_back(head->val);
            head = head->next;
        }
    }
    TreeNode* convert(int left , int right){
        if(left>right) return NULL;
        int mid = (left+right)/2;
        TreeNode* node = new TreeNode(this->a[mid]);
        if(left==right) return node;
        node->left = convert(left,mid-1);
        node->right= convert(mid+1,right);
        return node;
    }
    public :TreeNode* sortedListToBST(ListNode* head){
        this->makeArray(head);
        return convert(0,this->a.size()-1);
    }
};