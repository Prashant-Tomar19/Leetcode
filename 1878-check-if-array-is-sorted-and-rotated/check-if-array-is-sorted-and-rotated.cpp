class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        
        for(int i=0; i< nums.size(); i++){
            if(i<nums.size()- 1 && nums[i]>nums[i+1] ){
                count++;
                
            } 
            if(i==nums.size()-1 && nums[0]<nums[i]){
                count++;
            }
        }
        if(count>1){
            return false;
        }
    return true;
        
    }   

};