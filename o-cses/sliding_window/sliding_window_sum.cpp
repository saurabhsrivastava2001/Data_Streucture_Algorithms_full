#include<iostream>
#include<vector>
using namespace std;

long sliding_window_sum ( vector<long > arr,long k){
    vector<long > sum;
    long size=arr.size();
    long i=0;
    long j=0;
    long curr_sum=0;
    while(j<size){
        curr_sum+=arr[j];
        if (j-i+1<k){
            j++;
            continue;
        }
        sum.push_back(curr_sum);
        curr_sum-=arr[i];
        i++;
        j++;

    }
    long ans_xor=sum[0];
    for (long i=1;i<sum.size();i++){
        ans_xor^=sum[i];
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
    cout<<sliding_window_sum(arr,k);
}