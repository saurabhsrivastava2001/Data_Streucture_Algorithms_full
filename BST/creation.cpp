#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node{
    public:
        int data;
        node * left;
        node * right;

       node(int d){
        this-> data=d;
        this->left=NULL;
        this->right=NULL;
       } 
};
node* build_tree() {
    cout << "Enter the data: ";
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    node* root = new node(data);
    cout << "Enter the data for left of " << data << endl;
    root->left = build_tree();
    cout << "Enter the data for right of " << data << endl;
    root->right = build_tree();
    return root;
}


vector<vector<int>> level_order(node * root){
    vector<vector <int >> ans;
    queue <node *> q;
    if (root==NULL){
        return ans;
    }
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector <int > level;
        for (int i=0;i<size;i++){ 
            node * curr=q.front();
            q.pop();
            if (curr->left)q.push(curr->left); 
            if (curr->right)q.push(curr->right);
            level.push_back(curr->data);
        }
        ans.push_back(level);
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
    node * root=build_tree();
    vector <vector<int> > v=level_order(root);
    print(v);
}