#include <iostream>
#include <vector>
#include <queue>
using namespace std;



vector<int> func(vector<int> arr, int k)
{
    int n= arr.size();
    int i=0,j=0; 
    int maxi= INT32_MIN;
    queue<int>max_q;
    vector<int> ans;
    while(j<n){
        if (arr[j]>maxi){
            maxi=arr[j];
        }
        if (j-i+1<k){
            j++;
            continue;
        } 
        max_q.push(maxi);
        ans.push_back(max_q.front());
        if(arr[i]==max_q.front()){
            
        max_q.pop();
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