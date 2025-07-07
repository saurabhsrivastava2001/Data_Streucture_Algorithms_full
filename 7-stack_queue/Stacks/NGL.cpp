#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> NGL(int arr[],int n){
    vector<int> v;
    stack<int > s;
    for (int i=0;i<n;i++){
        if (s.size()==0){
            v.push_back (-1);
        }
        else if (s.size()>0 && s.top()>arr[i]){
            v.push_back(s.top());
        } 
        else if (s.size()>0 && s.top()<arr[i]){
            while(s.size()==0 && s.top()>arr[i]){
                s.pop();
            }
            if (s.size()==0){
                v.push_back(-1);

            }
            if (s.top()>arr[i]){
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);

    }
    return v;
}

int main(){
    int arr[5]={3,2,4,1};
    //op {-1,3,-1,4}
    vector<int > ans;
    ans =NGL(arr,5);
    for (int i=0;i<4;i++){
        cout<<ans[i]<<" ";
    }


}