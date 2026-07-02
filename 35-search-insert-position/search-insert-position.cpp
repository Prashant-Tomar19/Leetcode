class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         long long  left=0;
        long long right=nums.size()-1;
        long long mid=(left+right)/2;
        for(long long  i=0; i<nums.size(); i++){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                if( mid<nums.size()-1 && nums[mid+1]>target){
                    return mid+1;
                }
                else if(mid==nums.size()-1 && nums[mid]<target){
                    return mid+1;
                }
                left=mid+1;
                
            }
            else{
                if( mid!=0 && nums[mid-1]<target){

                    return mid;
                }
                else if (mid==0 && nums[mid]>target){
                    return mid;
                }
                right=mid;
            }
            mid=(left+right)/2;
        }
        return -1;

    }
};