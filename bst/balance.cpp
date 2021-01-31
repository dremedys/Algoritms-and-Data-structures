#include <iostream>
#include <vector>
using namespace std;
//given non balanced bst make it balanced bst
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //TreeNode(int x, TreeNode left, TreeNode right) : val(x), left(left), right(right) {}
};
class Solution {
public:
	vector<int> cnt; //just keeper node values in sorted way
	void dfs(TreeNode* root){ //inorder traversal
			if(not root) return;
			dfs(root->left);
			cnt.push_back(root->val);
			dfs(root->right);
	}

	TreeNode* build(int left, int right){  //takes to pointers and tries to make root
		if(left>right) return nullptr; //if they are here
		int mid=(left+right)/2;  //take middest index
		int val=cnt[mid];  //find its value
		TreeNode* temp=new TreeNode(val);  //it will be a root
		temp->left=build(left,mid-1);  //lesser elements make them left
		temp->right=build(mid+1,right); //bigger right
		return temp; //so return
	}

	TreeNode* balanceBST(TreeNode* root) {
		dfs(root);
		int n=cnt.size();
		return build(0,n-1);
	}
};