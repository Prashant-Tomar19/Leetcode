class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        int total=0;
        
        for(int i=0; i<cardPoints.size(); i++){
                total+=cardPoints[i];
        }
        if(k>=cardPoints.size()){
            return total;
        }
        int sum=0;
        int min_sum=INT_MAX;
        int left=0;
        int right=0;
        while(right<cardPoints.size()){
            if(right-left<cardPoints.size()-k){
                sum+=cardPoints[right];
                right++;
            }
            else{
                min_sum=min(min_sum,sum);
                sum-=cardPoints[left];
                sum+=cardPoints[right];
                left++;
                right++;
            }
        }
        min_sum = min(min_sum, sum);
        ans=total-min_sum;
        return ans;
    }
};