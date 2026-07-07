class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>current;
        count(current,candidates,target,ans,0,0);
        return ans;
    }
    void count(vector<int> &current, vector<int> &candidates , int target ,vector<vector<int>> &ans,int i,int total){
            if(i == candidates.size()) return;
            if(total==target){
                ans.push_back(current);
                return;
            }
            
        
        if(total+candidates[i]<=target){
            total+=candidates[i];
            current.push_back(candidates[i]);
            count(current,candidates,target,ans,i,total);
            total=total-candidates[i];
            current.pop_back();
        }

    
        
        count(current,candidates,target,ans,i+1,total);
    }
};