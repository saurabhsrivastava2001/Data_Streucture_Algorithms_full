// an array is given and the value at any index is given k places away or before we have to sort it 

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> k_sorted(vector <int> arr,int k){
    priority_queue<int, vector<int>, greater<int>> minh;
    vector <int> ans;
    for (int i=0;i<arr.size();i++){
        minh.push(arr[i]);
        if (minh.size()>k){
            ans.push_back(minh.top());
            minh.pop();
        }
    }
    while(minh.size()){
        ans.push_back(minh.top());
        minh.pop();
    }
    return ans;
}
int main(){
    vector<int> arr={6,5,3,2,8,10,9};
    vector<int > ans=k_sorted(arr,3);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}