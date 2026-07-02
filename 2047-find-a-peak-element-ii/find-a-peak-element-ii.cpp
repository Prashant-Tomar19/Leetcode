class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int low=0;
        int high=mat[0].size()-1;
        
        while(low<=high ){
            int row=0;
            int mid=low+(high-low)/2;
            for(int i=0; i<mat.size();i++){
                if(mat[i][mid] > mat[row][mid]){
                    row = i;
                }
            }
            int left  = (mid > 0)     ? mat[row][mid-1] : -1;
            int right = (mid < mat[0].size()-1)   ? mat[row][mid+1] : -1;

            
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
                    else if(right>mat[row][mid]){
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                
                
        }
        return {-1,-1};
    }
};