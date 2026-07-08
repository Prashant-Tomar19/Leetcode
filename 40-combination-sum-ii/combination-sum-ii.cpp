class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>current;
        count(current,candidates,target,ans,0,0);
        
        return ans;
    }
    void count(vector<int> &current, vector<int> &candidates , int target ,vector<vector<int>> &ans,int j,int total){
        if(total==target){
            ans.push_back(current);
            return;
        }
        if(j == candidates.size()) return;
        
        for(int i=j; i<candidates.size();i++){
            if(i>j && candidates[i]==candidates[i-1]){
                continue;
            }
            if(total+candidates[i]>target){
                break ;
            }
            total+=candidates[i];
            current.push_back(candidates[i]);
            count(current,candidates,target,ans,i+1,total);
            total-=candidates[i];
            current.pop_back();
        }

    }
};