class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right= *max_element(nums.begin(),nums.end());
        
        int ans=1;
        while(left<=right){
            int mid= left+(right-left)/2;
            long long result=0;
            for(int i=0; i<nums.size();i++){
                result+=(nums[i]+mid-1)/mid;
            }
            if(result<=threshold){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};