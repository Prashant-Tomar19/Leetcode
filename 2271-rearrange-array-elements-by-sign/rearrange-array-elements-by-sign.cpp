class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int j=0,k=1;
        vector<int>nums1=nums;
        for (int i=0; i<nums.size();i++ ){
            if(nums[i]>0){
                nums1[j]=nums[i];
                j=j+2;
            }
            else if(nums[i]<0){
                nums1[k]=nums[i];
                k=k+2;
            }
        }
    return nums1;
    }
};