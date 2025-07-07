#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_sum(vector<int> &arr){  
    vector <int> ans;
    int sum=0;
    for (auto i : arr){
        sum+=i;
        ans.push_back(sum);
    }
    return ans;
}

void print (vector<int> arr){
    cout<<" prefix sum:\n";
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}
void pref_of_range(vector<int> arr,int a , int b){
    cout<<"sum of subarray from range " <<a<< " to "<< b<<" is "<<(arr[b]-arr[a-1]);
}

int main() {

    vector<int> arr={1,3,5,10,6};
    // You can process the array here
    vector<int> ans= prefix_sum(arr);
    print (ans);
    pref_of_range(ans,2,4);
    return 0;
}
