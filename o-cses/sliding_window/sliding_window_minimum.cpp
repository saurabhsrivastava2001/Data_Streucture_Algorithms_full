#include<iostream>
#include<vector>
using namespace std;

long sliding_window_min ( vector<long > arr,long k){
    vector<long > min;
    long size=arr.size();
    long i=0;
    long j=0;
    long current_min=__LONG_MAX__;
    while(j<size){
        current_min=std::min(current_min,arr[j]);
        if (j-i+1<k){
            j++;
            continue;
        }
        min.push_back(current_min);
        i++;
        j++;

    }
    long ans_xor=min[0];
    for (long i=1;i<min.size();i++){
        ans_xor^=min[i];
    }
    return ans_xor;
}

int main(){
    long n,k,x,a,b,c;
    cin>>n>>k;
    cin>>x>>a>>b>>c;
    vector<long> arr(n);
    arr[0]=x;
    for (long i=1;i<n;i++){
        arr[i] = (a*(arr[i-1]) +b )%c;
    }
    cout<<sliding_window_min(arr,k);
}