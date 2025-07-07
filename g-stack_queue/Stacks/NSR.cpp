#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> NSR(int arr[],int size){
    vector <int> v;
    stack <int> s;
    for (int i=size-1;i>=0;i--){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.top()<arr[i]){
            v.push_back(s.top());
        }
        else {
            while(s.size()>0 && s.top()>arr[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(-1);
            }
            else if (s.top()<arr[i]){
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse (v.begin(),v.end());
    return v;
}

int main(){
    int n;
    vector<int> ans;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    // arr[]={1,2,5,3,6}
    //o/p[]={-1,-1,3,-1,-1}

    //arr2[]={3,2,5,3,1}
    //o/p[]={2,1,3,1,-1}
    ans=NSR(arr,n);
    if (ans.size()==0){
        cout<<"ans array is empty";
    }
    cout<<"the ans vector is"<<endl;
    for (int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
