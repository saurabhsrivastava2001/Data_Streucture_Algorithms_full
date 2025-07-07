#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Node{
    public:
        int data;
        Node * left;
        Node * right;

       Node(int d){
        this-> data=d;
        this->left=NULL;
        this->right=NULL;
       } 
};

Node * build_tree(Node * root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    if (data==-1){
        return NULL;
    }
    root=new Node (data);
    cout<<"enter the data for left of " <<data<<endl;
    root->left=build_tree(root->left);
    cout<<"enter the data for right of " <<data<<endl;
    root->right=build_tree(root->right);
    return root;
}

void preorder(Node * root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

vector<int> inorder(Node * root){
    vector<int> ans;
    stack <Node*> st;
    st.push(root);
    while (!st.empty())
    {
        Node * node= st.top();
        if (node->left) {
            st.push(node->left);
        }
        else {
            ans.push_back(st.top()->data);
            st.pop(); 
        }
        if (node ->right){
            st.push(node->right);
        }else {
            ans.push_back(st.top()->data);
            st.pop();
        }
    }
    return ans;
}


int main(){
    Node * root=NULL;
    //1 2 -1 5 -1 -1 111 5 -1 9 -1 -1 -1 
    root=build_tree(root);

    cout<< " the preorder traversal is :"<<endl;
    vector<int> ans= inorder(root);
    for (auto i : ans){
        cout<<i<<" ";
    }
    
}