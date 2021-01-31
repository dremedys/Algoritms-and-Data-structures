#include <iostream>
using namespace std;
int exists[1000000];
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
        Node* addMe= new Node(data);
        if(node == NULL){
            node = addMe;
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
};
int main(){
    int height=0;
    BST *bst= new BST();
    while(true){
        int n;
        cin>>n;
        if(n!=0){
            if(exists[n]!=1){
            bst->root= bst->insert(bst->root,n);
            exists[n]=1;}
            
        }
        else{
            height= bst->maxDepth(bst->root);
            break;
        }
    }
    cout<<height;
}