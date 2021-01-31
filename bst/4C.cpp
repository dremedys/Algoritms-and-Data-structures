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
        Node* addMe= new Node(data);
        if(node == NULL){
            node = addMe;
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
    int secondMax(Node* root) {
        if (root==NULL || (root->left==NULL && root->right==NULL))
            return -1;


        Node* parent = NULL, *child = root;
        
        while (child->right!=NULL) {
            parent = child;
            child = child->right;
        }

        if (child->left==NULL) 
            return parent->data;

        child = child->left;

        while (child->right!=NULL) 
            child = child->right;

        return child->data;
}
};
int main(){
    int ans;
    BST *bst= new BST();
    while(true){
        int n;
        cin>>n;
        if(n!=0){
            
            bst->root= bst->insert(bst->root,n);
        }
        else{
            ans= bst->secondMax(bst->root);
            break;
        }
    }
    cout<<ans<<endl;
}