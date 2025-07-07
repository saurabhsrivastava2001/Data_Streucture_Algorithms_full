#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> func(vector<int> arr, int k)
{
    int n= arr.size();
    int i=0,j=0; 
    queue<int>neg;
    vector<int> ans;
    while(j<n){
        if (arr[j]<0){
            neg.push(arr[j]);
        }
        if (j-i+1<k){
            j++;
            continue;
        }
        if(neg.size()==0){
            ans.push_back(-1);
        }
        else{
            ans.push_back(neg.front());
            if(arr[i]==neg.front()){
            neg.pop();
            }
        }
        i++;
        j++;
    }
    return ans;
}

void print(vector <int> ans)
{

    for (auto i : ans)
{
    cout<<i<<" ";
}}
int main(){
    vector <int> arr= {1,2,3,-81,4,3,-2,4,-12,7};
    vector<int> ans=func(arr,3);
    print(ans);
    return 0;
}