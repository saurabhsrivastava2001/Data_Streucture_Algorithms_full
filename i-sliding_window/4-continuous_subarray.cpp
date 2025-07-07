#include <iostream>
#include <vector>
using namespace std;

 bool func(vector <int > &arr, int k){
    bool ans= false;
    int n= arr.size();

    for (int i=0;i<n-1;i++){
        int sum=arr[i];
        for (int j=i+1;j<n;j++){
            sum+=arr[j];
            if(sum%k==0){
                cout<<sum;
                return true;
            }
        }
    }
    return false;
 }

int main(){
    vector <int> arr= {23,2,6,4,7};
    int k;
    cin>>k;
    if (func(arr,k)){
        cout<<"yes!";
    }
    else cout<<"no";
}