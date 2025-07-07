#include <iostream>
#include <vector>
using namespace std;
void subarray(vector<int> & arr){

    for(int i=0;i<arr.size();i++){
        vector<int> level;
        int large=arr[i];
        int mini=arr[i];
        int sum=0;
        for(int j=i;j<arr.size();j++){
            if (arr[j]>large){
                large=arr[j];
            }
            if (arr[j]<mini){
                mini=arr[j];
            }
            sum+=arr[j];
            level.push_back(arr[j]);
            for(int i=0;i<level.size();i++){
            cout<<level[i]<<" ";
        }cout<<" max__"<<large<< " ";
        cout<<" min__"<<mini<<" ";
        cout<<" sum__"<<sum<<endl;
        }
    }
} 
void print(vector<vector<int>>&arr){
    for (auto i : arr){
        for (auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}
int main(){
    vector<int> arr={9,2,7,20,23,4,3};
subarray(arr);
  
}