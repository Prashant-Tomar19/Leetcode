class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD= 1000000007;
        stack<int>st;
        int n = arr.size();
        vector<int> nextt(n);
        vector<int>prev(n);
        long long total=0;
        for(int i=arr.size()-1; i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                nextt[i] = arr.size();
            }
            else{
                nextt[i] = st.top();
            }
            st.push(i);
        }
        st=stack<int>();
        for(int i=0; i<arr.size();i++){
            while(!st.empty() &&arr[st.top()]>= arr[i]){
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

    long long cont = 1LL * left * right % MOD;
    cont = cont * arr[i] % MOD;

    total = (total + cont) % MOD;
}
        return total;
    }
};