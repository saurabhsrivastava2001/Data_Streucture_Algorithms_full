#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> nextPermutation(vector<int> nums){
    int n= nums.size();
    int dip;
    int nextBig;
    int gotDip=0;
    for (int i=n-2;i>=0;i++){
        if (nums[i]<nums[i+1]){
            dip=nums[i];
            gotDip=1;
            break;
        }
    }
    if (!gotDip){
        reverse(nums.begin(),nums.end());
        return nums;
    }
    for (int i=n-1;i>=0;i++){
        if (nums[i]>dip){
            nextBig=nums[i];
            break;
        }
    }

    swap(nums[dip],nums[nextBig]);

    reverse(nums.begin()+dip,nums.end());
    return nums;
}

int main(){
    vector<int> arr={765421};
    vector<int> ans= nextPermutation(arr);
    for(int i: ans){
        cout<<i <<" ";
    }
}