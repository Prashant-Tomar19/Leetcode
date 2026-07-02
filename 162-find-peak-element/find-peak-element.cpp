class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n =nums.size();
        int low= 0;
        int high=n-1;
        int mid= low+ (high-low)/2;
        
        while(low<high){
            if(mid<n-1 && nums[mid+1]>nums[mid] ){
                low=mid+1;
            }
            else if(mid>0 && nums[mid-1]>nums[mid] ){
                high=mid-1;
            }
            
            else{
                return mid;
            }
            
            mid= low+ (high-low)/2;
        }
        return mid;
    }
};