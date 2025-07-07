// return the k closest number of the given x;

# include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

vector <int > k_closest(vector<int> arr,int k, int x){
    priority_queue <pair<int,int>> maxh;
    vector<int> ans;
    for (int i=0;i<arr.size();i++){
        maxh.push({abs(arr[i]-x),arr[i]});
        if (maxh.size()>k){
            maxh.pop();
        }
    }
    for(int i=0;i<k;i++){
        ans.push_back(maxh.top().second);
        maxh.pop();
    }
    return ans;

}


int main(){
    vector<int> arr={5,6,7,8,9};
    vector<int > ans=k_closest(arr,3,7);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}