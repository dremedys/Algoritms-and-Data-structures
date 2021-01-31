#include <iostream>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
class BST{
    public:
    Node* root;
    BST(){
        root = NULL; 
    }
    Node* insert(Node *node,int data){
        
        if(node == NULL){
            node= new Node(data);
            return node;
        }
        if(node->data == data){
            return node;
        }
        else if(node->data < data ){
            node->right= insert(node->right,data);
        }
        else{
            node->left= insert(node->left,data);
        }
        return node;
    }

    int size(Node *node){
        if(node == NULL){
            return 0;
        }
        else{
            return (size(node->left) + 1 + size(node->right));
        }
    }
    
};
int main(){
    BST *bst= new BST();
    while(true){
        int n;
        cin>>n;
        if(n!=0 ){
          
            bst->root= bst->insert(bst->root,n);
           
            
        }
        else{
            cout<<bst->size(bst->root);
            break;
        }
    }
   
}