#include<iostream>
#include <map>
using namespace std;
//approch store the sum(key values pair (key = sum , val = index)) till the index , if we find the sum for which the sum-k is already strord -- we have got then we have to just subtract the current index - the stored (sum previous value )

// eg-- k=3 , current sum =9 , if we have the sum ( 9-k => 9-3 = 6 ) in the map (map <int , int > storing the sum weith the till indexes ( like sum =3 for index 0 , 5 for index 1 ----))  then we have to just subtract the value of 6 from the current value of index to get the sum k=>3 

//  [1,1,2,4,1,3,1]  k=3
// when we come to the 2 , then sum -k = 4-3 = 1 is in the map ? yes then we have to save the max len = max(max_len , len(= i-max[rem])) 
int max_subarray(int arr[],int n,int k){
    map<int,int> presum;// maps to store the presum values 
    int sum=0;
    int max_length=0;
    for (int i=0;i<n;i++){
        sum+=arr[i];
        if (sum==k){
            max_length=max(max_length,i+1);
        }
        int rem = sum-k;
        if(presum.find(rem)!=presum.end()){
            int len = i-presum[rem];
            max_length=max(max_length,len);
        }
        //if not found then we have to add it in the map we made to store the presum values 
        if (presum.find(sum)==presum.end()){
            presum[sum]=i;
        }
    }
    return max_length;
}

int Max_subarray_with_sum_optimal(int arr [],int n, int k){
    int sum=0;
    int max_len= 0;
    int right=0 ,left=0;
    while(right <n){
        
        if (sum==k){
            max_len= max(max_len,right-left);
        }while(sum>k && left<right){
            sum-=arr[left];
            left++;
        } 
        right ++;
        if(right <n){
            sum+=arr[right];
        }
    }
    return max_len;
}
int main(){
    int arr[15]={1,2,3,1,1,1,1,1,1,1,4,2,4,1,3};
    int k;
    cin>>k;
    cout<<Max_subarray_with_sum_optimal(arr,11,k);
}