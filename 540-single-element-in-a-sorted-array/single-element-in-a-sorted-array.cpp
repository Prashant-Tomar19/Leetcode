class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n =nums.size();
        int low=0;
        int high=n-1;
        int mid= low+(high-low)/2;
        while(low<high){
            if(mid%2==0 && mid<n-1){
                if(nums[mid+1]==nums[mid]){
                    low=mid+1;
                }
                else{
                    high=mid;
                }
            }
            else if(mid%2!=0 && mid>0 ){
                if(nums[mid-1]==nums[mid]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            mid= low+(high-low)/2;
        }
        return nums[mid];
    }
};