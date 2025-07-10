
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

// the main thing one should remember that the left view is the first element of the level order travesal and 
// right view is the last element of level in level order traversal 

pair<vector<int>,vector<int>> leftView(Node* &root) {

    
    pair<vector<int> , vector<int> > p;
    if (!root) return p ;

    queue<Node*> q; // for level order
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();  // number of nodes in the current level

        for (int i = 0; i < levelSize; ++i) {
            Node* curr = q.front();
            q.pop();

            // Store the first node of the level
            if (i == 0) p.first.push_back(curr->data); // if first of the level so goes in left view
            if (i == levelSize-1) p.second.push_back(curr->data); // if last of the traversal goes in the right view

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return p;
}
int main(){
    Node * root=NULL;
    //1 2 -1 3 -1 -1 4 5 -1 6 -1 -1 -1 
    root=build_tree();
    vector<int> leftV=leftView(root).first;
    vector<int> rightv=leftView(root).second;
    cout<<"left view"<<endl;
    for (auto it : leftV){
        cout<<it <<" ";
    }
    cout<<" right_view"<<endl;
    for (auto it : rightv){
        cout<<it <<" ";
    }
}