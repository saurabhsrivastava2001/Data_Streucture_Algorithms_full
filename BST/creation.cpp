#include <iostream>
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
    root->left=build_tree(root->right);
    return root;

}

void print_inorder(node* root) {
    if (root == NULL) {
        return;
    }
    
    cout << root->data << " ";  // Print root node
    print_inorder(root->left);         // Recursively print left subtree
    print_inorder(root->right);        // Recursively print right subtree
}

int main(){
    node * root=NULL;
    root=build_tree(root);
    print_inorder(root);
}