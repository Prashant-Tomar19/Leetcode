class Solution {
public:
    vector<vector<string>> partition(string s) {
        string temp="";
        vector<vector<string>> ans;
        vector<string> current;
        count(0,ans,current,temp,s);
        return ans;
    }
    void count(int i, vector<vector<string>> &ans, vector<string> &current,string &temp,string &s){
        if(i==s.size()){
            ans.push_back(current);
            return ;
            }
        for(int j=i; j<s.size();j++){
            if(ispalindrome(i,j,s)){
                temp = s.substr(i, j - i + 1);
                current.push_back(temp);
                count(j+1,ans,current,temp,s);
                current.pop_back();
            }
        }
    }
    bool ispalindrome(int left, int right ,string &s){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};