/// a balanced tree is a tree in which for any node   the diff bw the lft and right subtree is <=1 

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *left, *right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* build_tree(node* root) {
    cout << "Enter the data (-1 for NULL): ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new node(data);
    cout << "Enter the data for left of " << data << endl;
    root->left = build_tree(root->left);
    cout << "Enter the data for right of " << data << endl;
    root->right = build_tree(root->right);

    return root;
}


int height(node * root){
    if (root==NULL){
        return 0;
    }
    int lh,rh;
    lh=height(root->left);
    rh=height(root->right);
    
    return max(lh,rh)+1;
}


int check_balance(node * root ){
    if (root==NULL){
        return 0;
    }
    int lh,rh;
    lh=height(root->left);
    rh=height(root->right);
    
    if ( abs(lh-rh)>1)return -1; 
    return max(lh,rh)+1;
}
//[1 2 2 3 -1 -1 3 4 -1 -1 4]


int main() {
    node* root = NULL;
    root = build_tree(root);
    check_balance(root)==-1?cout<<"imbalance":cout<<"balance";
    return 0;
}