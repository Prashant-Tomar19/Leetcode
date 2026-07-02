class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
            
            for (int j = 0; j < n - 2; j++){
                
                if (j > 0 && nums[j] == nums[j - 1]) continue;
                int first=j+1;
                int second=n-1;
                int sum=0-(nums[j]);
                while(first<second){
                if((nums[first]+nums[second])==sum){
                    
                    ans.push_back({nums[j],nums[first],nums[second]});
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
    return ans;   
        
    }
};