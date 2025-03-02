
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
void printPreorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(Node* root){
    if(root == NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}
int search(Node* root, int key){
    if(root == NULL){
        return 0;
    }
    if(root->data == key){
        return 1;
    }
    if(root->data > key){
        return search(root->left, key);
    }
    return search(root->right, key);
}



int main(){
    Node* root = NULL;
    root = insert(root, 5);
    insert(root, 1);
    insert(root, 3);
    insert(root, 4);
    insert(root, 2);
    insert(root, 7);
printInorder(root);
cout<<endl;
printPreorder(root);
cout<<endl;
printPostorder(root);



    return 0;
}