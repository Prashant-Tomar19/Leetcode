class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum=0;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            maximum=max(sum,maximum);
            if(sum<0){
                sum=0;
            }
        }
        if(maximum==0){
            sort(nums.begin(),nums.end());
            return nums[nums.size()-1];
        }
        return maximum;
    }
};