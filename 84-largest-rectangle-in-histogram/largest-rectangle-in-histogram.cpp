class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
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
        int maxi=0;
        for (int i = 0; i < n; i++) {
            int count=heights[i]*(nextt[i]-prev[i]-1);
            maxi=max(maxi,count);
        }
        return maxi;
    }
};