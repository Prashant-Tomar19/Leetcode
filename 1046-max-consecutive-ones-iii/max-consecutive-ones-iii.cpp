class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int zeroes=0;
        int count=0;
        int max_count=0;
        int n=nums.size();
        while(right<n){
            if(nums[right]==0){
                if(zeroes<k){
                    zeroes++;
                    count++;
                }
                else{
                    while(zeroes>=k){
                        if(nums[left]==0){
                            zeroes--;
                        }
                        left++;
                        count--;
                    }
                    zeroes++;
                    count++;
                }

            }
            else{
                count++;
            }
            right++;
            max_count=max(count,max_count);
        }
        return max_count;
    }
};