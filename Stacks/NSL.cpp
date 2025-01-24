#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> NSL(int arr[],int size){
    vector <int> v;
    stack <int> s;
    for (int i=0;i<size;i++){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top()<arr[i]){
            v.push_back(s.top());
        }
        else if (s.size()>0 && s.top()>arr[i]){
            while(s.size()>0 && s.top()>arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            if (s.top()<arr[i]){
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
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
    //o/p[]={-1,1,2,2,3}
    ans=NSL(arr,n);
    cout<<"the ans vector is"<<endl;
    for (int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
