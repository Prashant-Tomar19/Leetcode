class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int sum=0; int count=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int rem=sum-k;
            if(sum==k){
                count++;
            }
            if(mpp.find(rem)!=mpp.end()){
                count+=mpp[rem];
            }
            mpp[sum]++;
        }
        return count;
    }
};