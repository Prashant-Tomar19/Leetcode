class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int el1=INT_MIN; int el2=INT_MIN;
        vector<int>ans;
        if(nums.size()==1){
                ans.push_back(nums[0]);
                return ans;
            }
        for(int i=0; i<nums.size(); i++){
            
            if(cnt1==0 && nums[i]!=el2){
                cnt1=1;
                el1=nums[i];  
            }
            else if(cnt2==0 && nums[i]!=el1){
                cnt2=1;
                el2=nums[i];  
            }
            
            else if(nums[i]==el1 && nums[i]!=el2){
                cnt1++;
            }
            else if(nums[i]==el2 && nums[i]!=el1){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
            
        }
        
        int cnt3=0,cnt4=0;
        for(int i=0; i<nums.size(); i++){
            if(el1==nums[i]){
                cnt3++;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(el2==nums[i]){
                cnt4++;
            }
        }
        if(el1==el2 && (cnt3+cnt4)>nums.size()/3){
            ans.push_back(el1);
            return ans;
        }
        if(cnt3>nums.size()/3){
            ans.push_back(el1);
        }
        if(cnt4>nums.size()/3){
            ans.push_back(el2);
        }
        return ans;

    
    }
};