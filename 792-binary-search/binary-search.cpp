class Solution {
public:
    int search(vector<int>& nums, int target) {
        long long  left=0;
        long long right=nums.size()-1;
        long long mid=(left+right)/2;
        for(long long  i=0; i<nums.size(); i++){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                left=mid+1;
                
            }
            else{
                right=mid;
            }
            mid=(left+right)/2;
        }
        return -1;

    }
};