#include<iostream>
#include <vector>
using namespace std;
        void rotateArray(vector<int>& nums, int k) {
            if (nums.size() ==1 || k==0){
                return ;
            }
            
            int arr[k];
            for( int i=0;i<k;i++){
                arr[i]=nums[i];
            }
            for (int i=0;i<nums.size();i++){  
                if (i<nums.size()-k){
                    nums[i]=nums[i+k];
                }
                else {
                    nums[i]=arr[i+k-nums.size()];
                }
            }
        }
   