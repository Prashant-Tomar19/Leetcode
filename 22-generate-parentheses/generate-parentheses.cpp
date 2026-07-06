class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        one_string(temp,n,ans);
        return ans;
    }
    int left=0;
    int right=0;
    void one_string(string &temp,int n, vector<string> &ans){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(left<n){
            temp.push_back('(');
            left++;
            one_string(temp,n,ans);
            temp.pop_back();
            left--;
        }
        
        if(left>right){
            temp.push_back(')');
            right++;
            one_string(temp,n,ans);
            temp.pop_back();
            right--;
        }
    }
};