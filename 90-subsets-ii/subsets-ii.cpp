class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> current;
        vector<vector<int>> ans;
        count(current,0,nums,ans);
        return ans;
    }
    void count(vector<int> &current, int i, vector<int> &nums , vector<vector<int>> & ans){
        ans.push_back(current);

        if(i==nums.size()){
            return;
        }
        for(int j=i; j<nums.size(); j++){
            if(j>i && nums[j-1]==nums[j]){
                continue;
            }
            current.push_back(nums[j]);
            count(current,j+1,nums,ans);
            current.pop_back();
        }
    }
};