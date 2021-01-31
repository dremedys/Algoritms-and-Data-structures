#include <iostream>
#include <cmath>
using namespace std;
int exists[10000000];
class Node{
    public:
    Node *left;
    Node *right;
    long long int data;

    Node(long long int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
class BST{
    public:
    Node *root;
    BST(){
        root = NULL; 
    }
    Node* insert(Node *node,long long int data){
        
        if(node == NULL){
            node= new Node(data);
            return node;
        }
        if(node->data < data ){
            node->right= insert(node->right,data);
        }
        else{
            node->left= insert(node->left,data);
        }
        return node;
    }

    int maxDepth(Node* node) {
        if (node==NULL) {
            return 0;
        }
        else {
            int leftDepth = maxDepth(node->left);
            int rightDepth = maxDepth(node->right);
            
            if (leftDepth > rightDepth) 
                return leftDepth+1 ;
            else
                return rightDepth+1;
        }
        
    }

    bool isBalanced(Node *node) {
        if(node==NULL){
            return true;
        }
        if (abs(maxDepth(node->left)-maxDepth(node->right))>1){
            return false;
        }
        return isBalanced(node->left) &&  isBalanced(node->right);
        
    }
};
int main(){
    
    BST *bst= new BST();
    while(true){
        long long int n;
        cin>>n;
        if(n!=0){
            if(exists[n]!=1)
            {bst->root= bst->insert(bst->root,n);   
            exists[n]=1;}      
        }
        else{
            if(bst->isBalanced(bst->root)){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
            break;
        }
    }
    
}