#include<iostream>
#include<vector>
using namespace std;

long sliding_window_xorr ( vector<long > arr,long k){
    vector<long > xorr;
    long size=arr.size();
    long i=0;
    long j=0;
    long curr_xorr=arr[j];
    j++;
    while(j<size){
        curr_xorr^=arr[j];
        if (j-i+1<k){
            j++;
            continue;
        }
        xorr.push_back(curr_xorr);
        curr_xorr^=arr[i];
        i++;
        j++;

    }
    long ans_xor=xorr[0];
    for (long i=1;i<xorr.size();i++){

        ans_xor^=xorr[i];
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
    cout<<sliding_window_xorr(arr,k);
}