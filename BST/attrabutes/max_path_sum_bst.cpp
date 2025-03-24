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
    root->right==build_tree();
    return root;
}

int max_path(node * root,int maxi){
    if (root==NULL){
        return 0;
    }
    int left_sum,right_sum;
    left_sum=max_path(root->left,maxi);
    right_sum=max_path(root->right,maxi);

    maxi=root->data + left_sum+right_sum;
    return root->data+ max(left_sum,right_sum);
}

int main(){
    node *root= build_tree();
    int ans=max_path(root,0);
    cout<<ans;
}