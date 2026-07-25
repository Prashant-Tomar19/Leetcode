class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
           count=count+nums[i];
        }
        int num=((n*(n+1))/2)-count;
        return num;
    }
};