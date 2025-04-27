class Solution {
    public:
        int secondLargestElement(vector<int>& nums) {
            //your code goes here
          
            if (nums.size()==0 || nums.size()==1){
                return -1;
            }
            int l=-10001;
            int s;
            for (int i=0;i<nums.size();i++){
                 if (nums[i]>=l){
                    s=l;
                    l=nums[i];
                 }
    
            }
            return s;
        }
    };