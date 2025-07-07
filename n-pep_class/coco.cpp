#include <iostream>
#include <vector>
using namespace std;

int max(vector<int>nums){
    int maxi=INT32_MIN;
    for( int i: nums){
        if (i>maxi){
            maxi=i;
        }
    }
    return maxi;
}


int calculate_ans(vector<int>nums,int ele){
    int req_hours=0;
    for (int i=0;i<nums.size();i++){
        req_hours+=
    }
}
int coco(vector<int> nums,int h){
    int start=1;
    int end=
}
int main(){
    vector<int >nums= {30,11,23,4,20};
    int h=6;
    coco(nums,h);
}