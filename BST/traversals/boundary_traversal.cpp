/* Boundary Traversal of a Binary Tree
Understanding the Problem Statement
Boundary traversal of a binary tree involves visiting nodes in a specific order:

Left Boundary (excluding leaf nodes)

Leaf Nodes (both left and right subtrees)

Right Boundary (excluding leaf nodes, but in reverse order)
*/

/*
Implementation Strategy
Traverse the Left Boundary---------------

Start from the root and keep moving left.

If there’s no left child, move to the right.

Stop before reaching a leaf node.

Traverse the Leaf Nodes------------

Do an inorder traversal and collect all leaf nodes.

Traverse the Right Boundary------------

Start from the root’s right child.

Keep moving right (if no right, move to the left).

Store nodes in a stack and print them in reverse order.
*/
#include <bits/stdc++.h>
using namespace std;

class node {
    public :
    int data;
    node *  left;
    node * right ;

    node (int d){
        this->data=d;
        this ->left=NULL;
        this ->right=NULL;
    }
};

node * build_tree(){
    cout<<"Enter the data : ";
    int data ;
    cin>>data;
    if (data ==-1){
        return NULL;
    }
    node * root=new node (data);
    cout<<"Enter the data for left of "<<data<<endl;
    root->left=build_tree();
    cout<<"Enter the data for right of "<<data<<endl;
    root->right=build_tree();
    return root;
}


// Function to print the left boundary (excluding leaf nodes)
void printLeftBoundary(node* root, vector<int>& result) {
    node* curr = root->left;
    while (curr) {
        if (curr->left || curr->right) result.push_back(curr->data);
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

// Function to print leaf nodes (Inorder Traversal)
void printLeaves(node* root, vector<int>& result) {
    if (!root) return;
    printLeaves(root->left, result);
    if (!root->left && !root->right) result.push_back(root->data);
    printLeaves(root->right, result);
}

// Function to print the right boundary (excluding leaf nodes, in reverse)
void printRightBoundary(node* root, vector<int>& result) {
    vector<int> temp;
    node* curr = root->right;
    while (curr) {
        if (curr->left || curr->right) temp.push_back(curr->data);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    reverse(temp.begin(), temp.end());
    result.insert(result.end(), temp.begin(), temp.end());
}

// Function to perform boundary traversal
vector<int> boundaryTraversal(node* root) {
    vector<int> result;
    if (!root) return result;

    result.push_back(root->data);  // Start with root
    if (root->left || root->right) {
        printLeftBoundary(root, result);
        printLeaves(root, result);
        printRightBoundary(root, result);
    }

    return result;
}
int main(){
    node * root= build_tree();
    vector<int > ans= boundaryTraversal( root);
    cout << "Boundary Traversal: ";
    for (int val : ans) cout << val << " ";
    cout << endl;

}