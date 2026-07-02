class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n =nums.size();
        int left=0;
        int right=0;
        for(int i=0; i<n; i++){
            if(left<nums[i]){
                left=nums[i];
            }
            right+=nums[i];
        }
        if(k>n){
            return -1;
        }
        int ans=-1;
        while(left<=right){
            int mid=left+(right-mid)/2;
            int sum=0;
            int count=1;
            for(int i=0; i<n;i++){
                if(sum+nums[i]<=mid){
                    sum+=nums[i];
                }
                else{
                    count++;
                    sum=nums[i];
                }
            }
            if(count<=k){
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