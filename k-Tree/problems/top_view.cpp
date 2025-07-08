#include<bits/stdc++.h>
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
Node* build_tree() {
    cout << "Enter the data: ";
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    Node* root = new Node(data);
    cout << "Enter the data for left of " << data << endl;
    root->left = build_tree();
    cout << "Enter the data for right of " << data << endl;
    root->right = build_tree();
    return root;
}

vector<int> top_view(Node * root){
    vector<int>ans;
    map <int ,int > mp;  // to store the axis and the first element --- we need the axis in sorted so I took the map 
    queue <pair<Node* , int >> q; //for level order traversal storing node with axis 

    q.push({root,0}); // pushing the root at 0 index 
    // if we go left then we will store that at curr_axis -1 and if go right then store it at the +1 axis
    while(!q.empty()){
        Node * node = q.front().first;
        int axis= q.front().second;
        q.pop();

        if (mp.find(axis)==mp.end()) mp[axis]=node ->data;
        if (node ->left != NULL)q.push({node->left,axis-1});
        if (node ->right != NULL)q.push({node->right,axis+1});
    }
    for (auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

void print(vector <vector<int>> v){
    for (int i=0;i<v.size();i++){
        for (int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Node * root=NULL;
    //1 2 -1 3 -1 -1 4 5 -1 6 -1 -1 -1 
    root=build_tree();
    vector<int> ans= top_view(root);
    for (auto it : ans){
        cout<<it <<" ";
    }
}



