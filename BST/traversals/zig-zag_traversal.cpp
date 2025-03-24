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
    root->right=build_tree();
    return root;
}

vector<vector<int>> zigZag(node *root){
    vector<vector<int>> ans;
    queue<node *> q;
    if (!root){
        return ans;
    }
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size=q.size();
        vector<int> level(size);
        for (int i=0;i<size;i++){
            node *temp=q.front();
            q.pop();
            int index=leftToRight?i:(size-1-i);//push the value at the ith if it is left to right else push it to the correspondig backwards
            level[index]=temp->data;
            cout<<"pushed "<<temp->data<<"at the "<< index<<" of the level"<<endl;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        ans.push_back(level);
        cout<<"pushed the level in the ans"<<endl;
        leftToRight= !leftToRight;
    }
    return ans;

}
void print(vector<vector<int>> ans){
    if (!ans.empty()){
        for (int i=0;i<ans.size();i++){
            for (int j=0;j<ans[i].size();j++){
                cout<< ans[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
    else cout<<" empty";
}
int main(){
    node * root=build_tree();

    vector<vector<int>> ans= zigZag(root);
    print(ans);
}   