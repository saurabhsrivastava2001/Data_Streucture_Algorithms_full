#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node{
    public:
        int data;
        node * left;
        node * right;

       node(int d){
        this-> data=d;
        this->left=NULL;
        this->right=NULL;
       } 
};

node * build_tree(node * root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    if (data==-1){
        return NULL;
    }
    root=new node (data);
    cout<<"enter the data for left of " <<data<<endl;
    root->left=build_tree(root->left);
    cout<<"enter the data for right of " <<data<<endl;
    root->right=build_tree(root->right);
    return root;
}

void preorder(node * root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node * root=NULL;
    //1 2 -1 5 -1 -1 111 5 -1 9 -1 -1 -1 
    root=build_tree(root);

    cout<< " the preorder traversal is :"<<endl;
    preorder(root);
    
}