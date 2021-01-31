#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }

        if (data <= node->data) 
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return node;
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    Node *findMin(Node *node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node *findMax(Node *node) {
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node *deleteNode(Node *node, int data) {
        if (node == NULL)
            return NULL;
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else {
            if (node->right == NULL && node->left == NULL)
                node = NULL;
            else if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else {
                Node *tmp = findMax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left, tmp->data);
            }
        }
    }
    int ut(int a,Node* node){
        if(node == NULL) return 0;
        if(node->data == a) return 0;
        if(node->data > a) return ut(a,node->left)+1;
        return ut(a,node->right)+1;
    }
    int dis(int a,int b, Node* node){
        if(node == NULL) return -1;
        if(node->data == a) return ut(b,node);
        if(node->data == b) return ut(a,node);
        if(node->data > a && node->data > b) return dis(a,b,node->left);
        if(node->data < a && node->data < b) return dis(a,b,node->right);
        return ut(b,node)+ut(a,node);
    }
};

int main() {
    BST *bst = new BST();
    bst->root = bst->insert(bst->root, 50);
    bst->root = bst->insert(bst->root,48 );
    bst->root = bst->insert(bst->root, 70);
    bst->root = bst->insert(bst->root, 30);
    bst->root = bst->insert(bst->root, 65);
    bst->root = bst->insert(bst->root, 90);
    bst->root = bst->insert(bst->root, 20);
    bst->root = bst->insert(bst->root, 32);
    bst->root = bst->insert(bst->root, 67);
    bst->root = bst->insert(bst->root, 98);
    bst->root = bst->insert(bst->root, 15);
    bst->root = bst->insert(bst->root,25 );
    bst->root = bst->insert(bst->root, 31);
    bst->root = bst->insert(bst->root,35 );
    bst->root = bst->insert(bst->root,66 );
    bst->root = bst->insert(bst->root,69 );
    bst->root = bst->insert(bst->root,94 );
    bst->root = bst->insert(bst->root,99 );

    // cout << bst->root->right->left->left->data;
    // bst->inOrder(bst->root);
    cout<< bst->dis(66,66,bst->root);
    return 0;
}