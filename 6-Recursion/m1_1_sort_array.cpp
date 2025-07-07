#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void insert(vector<int >& v,int temp){
    if(v.size()==0 || v[v.size()-1]<=temp){
        v.push_back(temp);
        return;
    }
    int val=v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
}


void sort(vector <int> & v){
    if (v.size()==0){
        return;
    }
    int temp=v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,temp);
}

void print(vector <int > v){
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}



int main() {
    int n=7;
    vector<int> arr={9,6,4,8,7,10,3};
    // desired output == 3,4,6,7,8,9,10
    

    print(arr);
    sort(arr);
    print(arr);
    return 0;
}