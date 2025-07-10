#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> NGR(int  nums[],int n){
    vector <int > v;
    stack <int > s;
    for (int i=n-1;i>=0;i--){
        if (s.size()==0){
            v.push_back(-1);
        }
        else if (s.size()>0 && s.top()> nums[i]){
            v.push_back(s.top());
        }
        else if (!s.empty() && s.top()< nums[i]){
            //pop the stack untill the stack is empty or s.pop()> nums[i]
            while(!s.empty() && s.top()< nums[i]){
                s.pop();
            }
            if (s.empty()){
                v.push_back(-1);
            }
            if (s.top()> nums[i]){
                v.push_back(s.top());
            }

        }
        s.push( nums[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}
int main(){
    int  nums[4]={1,3,2,4};
    //op={3,4,4,-1}
    vector <int > ans;

    ans=NGR( nums,4);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<"  ";
    }
}