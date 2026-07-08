class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>current;
        vector<vector<int>>ans;
        int nums[9]={1,2,3,4,5,6,7,8,9};
        count(current,0,k,n,nums,ans,0);
        return ans;
    }
    void count(vector<int> &current, int i,int k,int n , int *nums , vector<vector<int>> & ans,int total){
        if(total==n && current.size()==k){
            ans.push_back(current);
            return;
        }
        if(i==9){
            return;
        }
        for(int j=i; j<9; j++){
            if(j>i && nums[j-1]==nums[j]){
                continue;
            }
            if(total+nums[j]>n || current.size()+1>k){
                break;
            }
            current.push_back(nums[j]);
            total+=nums[j];
            count(current,j+1,k,n,nums,ans,total);
            current.pop_back();
            total-=nums[j];
        }
    }
};