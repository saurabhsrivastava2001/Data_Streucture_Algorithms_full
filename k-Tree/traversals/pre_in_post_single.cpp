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

vector<vector<int>> preInPost(Node * root){
    vector<vector<int>> ans;
    stack <pair<Node * , int>> st;
    st.push({root,1});
    vector<int> pre, in , post ;
    if (!root)return ans;
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if (it.second==1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->left)st.push({it.first->left,1});
        }
        else if (it.second==2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if ( it.first->right)st.push({it.first->right,1});
        }
        else post.push_back(it.first->val);
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}


int main(){
    Node * root= build_tree();
    vector<vector<int>> ans=preInPost(root);
    for (auto it : ans){
        for (auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}