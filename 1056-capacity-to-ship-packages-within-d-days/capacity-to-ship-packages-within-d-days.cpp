class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int right=0;
        for(int i=0; i<n; i++){
            right+=weights[i];
        }
        int left= *max_element(weights.begin(),weights.end());
        int num=0;
        
        while(left<=right){
            int ans=1;
            int sum=0;
            int mid=left + (right-left)/2;
            for(int i=0; i<n; i++){
                if(sum+weights[i]>mid){
                    ans++;
                    sum=weights[i];
                    
                }
                else{
                    sum+=weights[i];
                }
                
            }
            if(ans<=days){
                num=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return num;
    }
};