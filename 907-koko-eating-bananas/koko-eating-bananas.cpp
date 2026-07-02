class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int right = *max_element(piles.begin(), piles.end());
        int left= 1;
        
        int ans=right;
        while(left<=right){
            int mid= left+(right-left)/2;
            long long count=0;
            for(int i=0; i<n ;i++){
               count=count+((piles[i]+mid-1)/mid);
                
            }
            if(count<=h){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
            
        
        }
        return ans;
    }
};