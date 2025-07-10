
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode * left;
        TreeNode * right;

       TreeNode(int d){
        this-> val=d;
        this->left=NULL;
        this->right=NULL;
       } 
};

TreeNode* build_tree() {
    cout << "Enter the val: ";
    int val;
    cin >> val;
    if (val == -1) {
        return NULL;
    }
    TreeNode* root = new TreeNode(val);
    cout << "Enter the val for left of " << val << endl;
    root->left = build_tree();
    cout << "Enter the val for right of " << val << endl;
    root->right = build_tree();
    return root;
}

bool isMirror(TreeNode * left , TreeNode * right){
    //IBH method 
    //base-- what could be the lowest point of recursion (leaf)
    if (left==NULL || right ==NULL) return left==right ; // if dont have left or right or both then compare them and return( true if both are not , false if only one is present )    // if both are equal then true else false 
    if (left->val !=right->val) return false;// else if values are present then and diff then false
    

    // now we will compare both (the left of left and right of right ) and ( right of left and left of right ) 
    // if any condition fails then returns false are line 37 
    return (isMirror(left->left,right->right) && isMirror(left->right ,right->left)); // go check for left and right used && bcz if any fails then return false 
}

bool mirror(TreeNode * root){
    return root==NULL || isMirror(root->left,root->right);
}

int main(){
    TreeNode * root=NULL;
    //1 2 -1 3 -1 -1 4 5 -1 6 -1 -1 -1 
    root=build_tree();
    cout<< " the tree is "<< ((mirror)? " a":"not a ")<<  "mirror "; 
}