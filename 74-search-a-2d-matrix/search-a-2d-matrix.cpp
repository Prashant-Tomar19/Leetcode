class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=matrix[0].size()-1;
        int right=0;
        int ans=false;

        while(left>=0 && right<=matrix.size()-1){
            if(matrix[right][left]==target){
                ans=true;
                break;
            }
            else if(matrix[right][left]<target){
                right++;
            }
            else{
                left--;
            }
        }
        return ans;
    }
};