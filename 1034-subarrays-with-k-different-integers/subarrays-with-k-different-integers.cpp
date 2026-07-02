class Solution {
public:
    int at_most(int a,vector<int>& nums){
            int left=0;
            int right=0;
            int distinct=0;
            int total=0;
            unordered_map<int,int>mp;
            int n=nums.size();
            while(right < n && left<=right){
                if(mp[nums[right]] > 0 || distinct < a){
                    if(mp[nums[right]]==0){
                    distinct++;
                    }
                    mp[nums[right]]++;
                    int addition=right-left+1;
                    total+=addition;
                    right++; 
                }
                else{
                    mp[nums[left]]--;
                    if(mp[nums[left]]==0){
                        distinct--;
                    }
                    
                    left++;
                }
               
            }
            return total;
        }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int x=at_most(k,nums);
        int y=at_most(k-1,nums);
        return x-y;

    }
};