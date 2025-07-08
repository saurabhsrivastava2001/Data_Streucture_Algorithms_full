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

Stop before reaching a leaf Node.

Traverse the Leaf Nodes------------

Do an inorder traversal and collect all leaf nodes.

Traverse the Right Boundary------------

Start from the root’s right child.

Keep moving right (if no right, move to the left).

Store nodes in a stack and print them in reverse order.
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
    int val;
    Node *  left;
    Node * right ;

    Node (int d){
        this->val=d;
        this ->left=NULL;
        this ->right=NULL;
    }
};

Node * build_tree(){
    cout<<"Enter the val : ";
    int val ;
    cin>>val;
    if (val ==-1){
        return NULL;
    }
    Node * root=new Node (val);
    cout<<"Enter the val for left of "<<val<<endl;
    root->left=build_tree();
    cout<<"Enter the val for right of "<<val<<endl;
    root->right=build_tree();
    return root;
}
void addLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;   // taking a  pointer to traverse 
    while (curr) { 
        if (curr->left || curr->right) res.push_back(curr->val);// not a leaf Node  
        if (curr->left) curr = curr->left; // move left left left
        else curr = curr->right; // if  not left then right 
    }
}
void addleaves(Node* root, vector<int>& res) {
    if (!root->left && ! root->right) res.push_back(root->val); // only check we need to do is that is the node is leaf
    if(root->left) addleaves(root->left,res); // go in left depth find leaf
    if(root->right) addleaves(root->right,res); // go in the right depth find leaf node
}
void addRightBoundary(Node* root, vector<int>& res) {
    vector<int> temp;    // we need a data structure to store the values because we need to do the right in the reverse order
    Node* curr = root->right; // reverse
    while (curr) {
        if (curr->left || curr->right) temp.push_back(curr->val); // if its not leafnode push it 
        if (curr->right) curr = curr->right; // go right right right 
        else curr = curr->left; // if not right then go left
    }
    reverse(temp.begin(), temp.end()); // revrse it and the push it to the ans
    res.insert(res.end(), temp.begin(), temp.end()); // pushing it on the ans
}

// Function to perform boundary traversal
vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;

    res.push_back(root->val);  // Start with root
    if (root->left || root->right) { // if it has nodes
        addLeftBoundary(root, res); // add the left boundary first 
        addleaves(root, res); // add the leaf nodes 
        addRightBoundary(root, res); // add the right boundary
    }
    return res; 
}

void printlevelorder(Node * &root){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int size= q.size();
        for (int i=0;i<size;i++){
            Node * curr = q.front();
            q.pop();
            cout<<curr->val<<" ";
            if (curr->left)q.push(curr-> left);
            if (curr-> right)q.push(curr-> right);
        }
        cout<<endl;
    }
}
int main(){
    Node * root= build_tree();
    vector<int > ans= boundaryTraversal( root);
    cout << "Boundary Traversal: ";
    for (int val : ans) cout << val << " ";
    printlevelorder(root);
    cout << endl;

}