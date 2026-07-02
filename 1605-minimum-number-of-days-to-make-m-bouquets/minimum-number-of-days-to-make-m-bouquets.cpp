class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left=1;
        int n= bloomDay.size();
        if((long long)m*k>n) return -1;
        int ans=-1;
        int right= *max_element(bloomDay.begin(),bloomDay.end());
        while(left<=right){
            int mid= left+ (right-left)/2;
            int count=0;
            int bq=0;
            for(int i=0; i<n; i++){
                if(bloomDay[i]<=mid){
                    count+=1;
                    if(count==k){
                        count=0;
                        bq+=1;
                    }
                }
                
                else{
                    count=0;
                } 
            }
            if(bq>=m){
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