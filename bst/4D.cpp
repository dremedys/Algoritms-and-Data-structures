#include <iostream>
using namespace std;
int exists[10000000];
class Node{
    public:
    Node* left;
    Node* right;
    long long int data;

    Node(long long int data){
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

    

    void printTree(Node* node) {
        if (node == NULL) 
            return;
        printTree(node->left);
        cout<<node->data<<"\n";
        printTree(node->right);
    }  

};
int main(){
    BST *bst= new BST();
    while(true){
        long long int n;
        cin>>n;
        if(n!=0){
            if(exists[n]!=1){
            bst->root= bst->insert(bst->root,n);    
            exists[n]=1;}     
        }
        else{
            break;
        }
    }
    bst->printTree(bst->root);
}