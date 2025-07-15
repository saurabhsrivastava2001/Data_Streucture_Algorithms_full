//if root is equal to the sum of the childrens 

#include<bits/stdc++.h>
using namespace std;
class TreeNode{public :
    int val;
    TreeNode * left;
    TreeNode * right;

    
    TreeNode(int val):val(val),left(nullptr),right(nullptr){}
    TreeNode():left(nullptr),right(nullptr){};

    
    static TreeNode * buildTree (){
    int val;
    cin>>val;
    if (val==-1 ){
        return nullptr;
    }
    
    TreeNode * root= new TreeNode(val);
    cout<<"enter the left of "<<val<<endl;
    root->left=buildTree();
    cout<<"enter the right of "<<val<<endl;
    root->right=buildTree();
    

    return root;
    }
    
};

class Solution {
public:
    static bool checkTree(TreeNode* root) {
        if(!root)return true;
        int sum=0;
        if (root->left)sum+=root->left->val;
        if (root->right)sum+=root->right->val;
        if (sum==root->val)return true;
        else return false ;
        return (checkTree(root->left) && checkTree(root->right));
    }
    static void reorder(TreeNode * & root){
        if (! root) return;
        int sum =0;
        if (root->left)sum+=root->left->val;
        if (root->right)sum+=root->right->val;

        if (sum>root->val)root->val=sum;
        else{
            if (root->left)root->left->val=root->val;
            if (root->right)root->right->val=root->val;
        }

        reorder(root->left);
        reorder(root->right);

        int total_left_right=0;
        if(root->left)total_left_right+=root->left->val;
        if(root->right)total_left_right+=root->right->val;

        if (root->left or root->right) root->val=total_left_right;
        return ;
    }
};

int main(){
    cout<<"lets build the tree first"<<endl; 
    cout<< " enter the values"<<endl;   
    TreeNode * root=TreeNode::buildTree();
     (Solution::checkTree(root))? cout<<" tree follows root equal sum ":cout<<"doesn't follow : calling the function to make it "<<endl,Solution::reorder(root), (Solution::checkTree(root)?cout<<"now fixed"<<endl:cout<<"still not fixed");
}