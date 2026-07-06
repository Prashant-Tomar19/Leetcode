class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>power_set;
        vector<int>temp;
        generate(power_set,nums,temp,0);
        return power_set;
    }
    void generate(vector<vector<int>> &power_set, vector<int> &nums , vector<int> &temp, int i){
        if(i==nums.size()){
            power_set.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        generate(power_set,nums,temp,i+1);
        temp.pop_back();

        generate(power_set,nums,temp,i+1);
    }
};