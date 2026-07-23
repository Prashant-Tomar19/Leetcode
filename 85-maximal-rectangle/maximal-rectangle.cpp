class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n =matrix[0].size();
        vector<int>heights(n,0);
        int maxi=0;
        stack<int>st;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]=='1'){
                    heights[j]+=1;
                }
                else{
                    heights[j]=0;
                }
            }
            vector<int> nextt(n);
            vector<int>prev(n);
            for(int i=heights.size()-1; i>=0;i--){
                while(!st.empty() && heights[st.top()]>heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    nextt[i] = heights.size();
                }
                else{
                    nextt[i] = st.top();
                }
                st.push(i);
            }
            st=stack<int>();
            for(int i=0; i<heights.size();i++){
                while(!st.empty() &&heights[st.top()]>= heights[i]){
                    st.pop();
                }
                if(st.empty()){

                prev[i] = -1;
                }
                else{
                    prev[i] = st.top();
                }
                st.push(i);
            }
            for (int i = 0; i < n; i++) {
                int count=heights[i]*(nextt[i]-prev[i]-1);
                maxi=max(maxi,count);
            }
            st=stack<int>();
        }
        return maxi;
    }
};