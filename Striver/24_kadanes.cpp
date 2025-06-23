//maximum subarray sum
#include <iostream>
#include <vector>
using namespace std;
int kadanes(vector<int> arr){
    int maxi=INT32_MIN;
    int sum=0;
    for (int i=0;i<arr.size();i++){
        sum+=arr[i];
        if (sum>maxi){
            maxi=sum;
        }
        if (sum<0){
            sum=0;
        }
    }
    return maxi;
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // You can process the array here
    cout<<kadanes(arr);
    return 0;
}