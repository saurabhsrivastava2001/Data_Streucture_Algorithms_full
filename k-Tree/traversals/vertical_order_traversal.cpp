#include <bits/stdc++.h>

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

vector<vector<int>> vertical_order(Node * root){
    map <int , map<int ,multiset<int>>> nodes;
    queue <pair<Node * ,pair<int ,int>>> todo;
    todo.push({root,{0,0}});

    while (!todo.empty()){

    }
    
    
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
    vector<vector<int>> v =level_order(root);
    print(v);
}