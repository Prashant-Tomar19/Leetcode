class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0;i<n-3; i++){ 
            if (i > 0 && nums[i] == nums[i - 1]) continue;  
            for (int j = i+1; j < n - 2; j++){
                
                if (j > i+1 && nums[j] == nums[j - 1] ) continue;
                int first=j+1;
                int second=n-1;
                long long sum=(long long)target-(nums[j]+nums[i]);
                while(first<second){
                if((nums[first]+nums[second])==sum){
                    
                    ans.push_back({nums[i],nums[j],nums[first],nums[second]});
                    while (first < second && nums[first] == nums[first + 1]) first++;
                    
                    while (first < second && nums[second] == nums[second - 1]) second--;
                    first++;
                    second--;
                }
                
                    
                
                else if((nums[first]+nums[second])>sum){
                    second--;
                }
                else {
                    first++;
                }
                }
            }
        }
    return ans;   
        
    }
};
    