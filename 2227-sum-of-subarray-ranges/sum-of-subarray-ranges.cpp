class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int> nextt(n);
        vector<int>prev(n);
        long long total=0;
        for(int i=nums.size()-1; i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()){
                nextt[i] = nums.size();
            }
            else{
                nextt[i] = st.top();
            }
            st.push(i);
        }
        st=stack<int>();
        for(int i=0; i<nums.size();i++){
            while(!st.empty() &&nums[st.top()]>= nums[i]){
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
            int left = i - prev[i];
            int right = nextt[i] - i;

            long long cont = 1LL * left * right;
            cont = cont * nums[i] ;

            total = total + cont;
        }

        st=stack<int>();
        nextt=vector<int>(n);
        prev=vector<int>(n);
        long long total1=0;
        for(int i=nums.size()-1; i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty()){
                nextt[i] = nums.size();
            }
            else{
                nextt[i] = st.top();
            }
            st.push(i);
        }
        st=stack<int>();
        for(int i=0; i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<= nums[i]){
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
            int left = i - prev[i];
            int right = nextt[i] - i;

            long long cont = 1LL * left * right;
            cont = cont * nums[i] ;

            total1 = total1 + cont;
        }
        
    return total1-total;
    }
};